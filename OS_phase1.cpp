#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

char M[100][4];
char IR[4];
char R[4];
int IC;
bool C;
char Buffer[41];
int m;
int SI;

void INIT();
void LOAD(ifstream &infile, ofstream &outfile);
void START_EXECUTION(ifstream &infile, ofstream &outfile);
void MOS(ifstream &infile, ofstream &outfile);
void READ(ifstream &infile);
void WRITE(ofstream &outfile);
void TERMINATE(ofstream &outfile);
void print_memory();

int main()
{
    cout << "\n[STEP 1] Starting OS Phase-I (Multi-Job Support)...\n";

    ifstream infile("input.txt");
    ofstream outfile("output.txt", ios::out);

    if (!infile.is_open())
    {
        cerr << "Cannot open 'input.txt'.\n";
        return 1;
    }
    if (!outfile.is_open())
    {
        cerr << "Cannot create 'output.txt'.\n";
        return 1;
    }

    cout << "Files opened. Starting batch processing...\n";

    int jobCount = 0;

    while (!infile.eof())
    {
        LOAD(infile, outfile);
        if (infile.eof())
            break;
        jobCount++;
        cout << "\n========== Executing Job #" << jobCount << " ==========\n";
        START_EXECUTION(infile, outfile);
    }

    cout << "\n[DONE] Total jobs executed: " << jobCount << "\n";
    cout << "\n[MEMORY DUMP] Final state of memory:\n";
    print_memory();

    infile.close();
    outfile.close();
    return 0;
}

void INIT()
{
    cout << "\n[INIT] Resetting CPU registers and memory for new job...\n";

    for (int i = 0; i < 4; i++)
    {
        IR[i] = '*';
        R[i] = '*';
    }

    IC = 0;
    C = false;
    SI = 0;

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 4; j++)
            M[i][j] = '*';

    cout << "[INIT] Complete. Memory and registers are clean.\n";
}

void LOAD(ifstream &infile, ofstream &outfile)
{
    while (infile.getline(Buffer, 41))
    {
        if (strncmp(Buffer, "$AMJ", 4) == 0)
        {
            cout << "\n[LOAD] $AMJ found -> New job starting.\n";
            INIT();
            m = 0;
        }
        else if (strncmp(Buffer, "$DTA", 4) == 0)
        {
            cout << "[LOAD] $DTA found -> Program loaded. Switching to execution.\n";
            break;
        }
        else if (strncmp(Buffer, "$END", 4) == 0)
        {
            cout << "[LOAD] $END found -> Job boundary reached.\n";
            continue;
        }
        else
        {
            if (m >= 100)
            {
                cerr << "[ERROR] Memory Overflow! Cannot load more instructions.\n";
                exit(0);
            }

            int buffer_len = strlen(Buffer);
            int buffer_index = 0;
            int limit = m + 10;

            cout << "[LOAD] Program card -> loading into M[" << m << "..] : " << Buffer << "\n";

            while (m < limit && buffer_index < buffer_len && m < 100)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (buffer_index < buffer_len)
                        M[m][j] = Buffer[buffer_index++];
                    else
                        M[m][j] = '*';
                }
                m++;
            }

            if (m % 10 != 0)
                m = ((m / 10) + 1) * 10;

            cout << "[LOAD] Memory pointer advanced to m=" << m << "\n";
        }
    }
}

void START_EXECUTION(ifstream &infile, ofstream &outfile)
{
    cout << "\n[CPU] Starting fetch-decode-execute cycle at IC=0\n";
    IC = 0;

    while (true)
    {
        if (IC >= 100)
        {
            cerr << "[ERROR] IC out of bounds: " << IC << ". Stopping.\n";
            break;
        }

        for (int i = 0; i < 4; i++)
            IR[i] = M[IC][i];
        IC++;

        char op1 = IR[0];
        char op2 = IR[1];

        if (op1 == 'G' && op2 == 'D')
        {
            cout << "[CPU] GD" << IR[2] << IR[3] << " -> System call READ\n";
            SI = 1;
            MOS(infile, outfile);
        }
        else if (op1 == 'P' && op2 == 'D')
        {
            cout << "[CPU] PD" << IR[2] << IR[3] << " -> System call WRITE\n";
            SI = 2;
            MOS(infile, outfile);
        }
        else if (op1 == 'H')
        {
            cout << "[CPU] H -> Halt. Job complete.\n";
            SI = 3;
            MOS(infile, outfile);
            break;
        }
        else
        {
            int operand = 0;
            if (isdigit(IR[2]) && isdigit(IR[3]))
                operand = (IR[2] - '0') * 10 + (IR[3] - '0');
            else
            {
                cerr << "[CRITICAL] Invalid operand in IR. Stopping.\n";
                break;
            }

            if (op1 == 'L' && op2 == 'R')
            {
                cout << "[CPU] LR" << operand << " -> R <- M[" << operand << "]\n";
                for (int i = 0; i < 4; i++)
                    R[i] = M[operand][i];
            }
            else if (op1 == 'S' && op2 == 'R')
            {
                cout << "[CPU] SR" << operand << " -> M[" << operand << "] <- R\n";
                for (int i = 0; i < 4; i++)
                    M[operand][i] = R[i];
            }
            else if (op1 == 'C' && op2 == 'R')
            {
                C = true;
                for (int i = 0; i < 4; i++)
                {
                    if (R[i] != M[operand][i])
                    {
                        C = false;
                        break;
                    }
                }
                cout << "[CPU] CR" << operand << " -> Compare result: C=" << (C ? "TRUE" : "FALSE") << "\n";
            }
            else if (op1 == 'B' && op2 == 'T')
            {
                if (C)
                {
                    cout << "[CPU] BT" << operand << " -> Branch taken. IC set to " << operand << "\n";
                    IC = operand;
                }
                else
                    cout << "[CPU] BT" << operand << " -> Branch NOT taken.\n";
            }
            else
            {
                cerr << "[ERROR] Unknown opcode: " << op1 << op2 << ". Stopping.\n";
                break;
            }
        }
    }
}

void MOS(ifstream &infile, ofstream &outfile)
{
    switch (SI)
    {
    case 1:
        READ(infile);
        break;
    case 2:
        WRITE(outfile);
        break;
    case 3:
        TERMINATE(outfile);
        break;
    }
}

void READ(ifstream &infile)
{
    IR[3] = '0';
    int operand = (IR[2] - '0') * 10 + (IR[3] - '0');

    if (operand + 10 > 100)
    {
        cerr << "[ERROR] Memory Boundary Exceeded in READ (addr=" << operand << ")\n";
        exit(0);
    }

    if (infile.getline(Buffer, 41))
    {
        if (strncmp(Buffer, "$END", 4) == 0)
        {
            cerr << "[ERROR] Out of Data - GD encountered $END.\n";
            exit(0);
        }

        cout << "[READ] Data card read -> \"" << Buffer << "\" -> M[" << operand << ".." << operand + 9 << "]\n";

        int len = strlen(Buffer);
        int b_idx = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 4; j++)
                M[operand + i][j] = (b_idx < len) ? Buffer[b_idx++] : '*';
    }
    else
    {
        cerr << "[ERROR] Unexpected end of file during READ.\n";
        exit(0);
    }
}

void WRITE(ofstream &outfile)
{
    IR[3] = '0';
    int operand = (IR[2] - '0') * 10 + (IR[3] - '0');

    if (operand + 10 > 100)
    {
        cerr << "[ERROR] Memory Boundary Exceeded in WRITE (addr=" << operand << ")\n";
        exit(0);
    }

    memset(Buffer, '*', 40);
    int b_idx = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 4; j++)
            Buffer[b_idx++] = M[operand + i][j];

    cout << "[WRITE] M[" << operand << ".." << operand + 9 << "] -> output.txt : \"";
    for (int i = 0; i < 40; i++)
    {
        if (Buffer[i] != '*')
        {
            outfile << Buffer[i];
            cout << Buffer[i];
        }
    }
    outfile << "\n";
    cout << "\"\n";
}

void TERMINATE(ofstream &outfile)
{
    cout << "[TERMINATE] Writing job separator to output.txt\n";
    outfile << "\n\n";
}

void print_memory()
{
    cout << "\n//=========== Memory Dump ===========//\n";
    for (int i = 0; i < 100; i++)
    {
        cout << "M[" << (i < 10 ? "0" : "") << i << "]: ";
        for (int j = 0; j < 4; j++)
            cout << M[i][j];
        cout << "\n";
        if ((i + 1) % 10 == 0)
            cout << "//---------------------------//\n";
    }
}