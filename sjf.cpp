#include < iostream.h > #include < conio.h >
    void main() {
        clrscr();
        int p[4], at[4], bt[4], ft[4], tat[4], wt[4], stat, swt;
        int i, j, k, temp1, temp2, temp3, loc, min, sum;
        for (i = 0; i <= 3; i++) {
            cout << "enter the process number : ";
            cin >> p[i];
            cout << "enter arrival time for p" << p[i] << " : ";
            cin >> at[i];
            cout << "enter burst time for p" << p[i] << " : ";
            cin >> bt[i];
        }
        for (j = 1; j <= 2; j++) {
            min = bt[j];
            for (k = j + 1; k <= 3; k++) {
                if (bt[k] < min) {
                    min = bt[k];
                    loc = k;
                }
            }
            temp1 = bt[loc];
            bt[loc] = bt[j];
            bt[j] = temp1;
            temp2 = at[loc];
            at[loc] = at[j];
            at[j] = temp2;
            temp3 = p[loc];
            p[loc] = p[j];
            p[j] = temp3;
        }
        for (i = 0; i <= 3; i++) {
            sum = sum + bt[i];
            ft[i] = sum;
            tat[i] = ft[i] - at[i];
            wt[i] = tat[i] - bt[i];
        }
        clrscr();
        cout << "\n******************************************";
        cout << "\nprocess\tatime\tbtime\tftime\ttat\twt";
        for (i = 0; i <= 3; i++) {
            cout << endl << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ft[i] << "\t" << tat[i] << " \t" << wt[i];
        }
        for (i = 0; i <= 3; i++) {
            stat = stat + tat[i];
            swt = swt + wt[i];
        }
        cout << "\n******************************************";
        cout << "\naverage turnaroundtime " << (double) stat / 4;
        cout << "\naverage waiting time " << (double) swt / 4;
        getch();
    }