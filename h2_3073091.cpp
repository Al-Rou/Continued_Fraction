#include <iostream>
#include <iomanip>

using namespace std;

/*********
Task 1
*********/

struct kettenBr
{
    int ketEl;
    struct kettenBr *next;
};

const int zifNachPunkt = 15;


/*********
Task 2
*********/

kettenBr* initialFunk (kettenBr* head, int w)
{
    kettenBr* initEl = new kettenBr;
    initEl->ketEl = w;
    initEl->next = nullptr;
    kettenBr* woEl = new kettenBr;
    woEl = head;
    if (head == nullptr)
    {
        head = initEl;
        return head;
    }
    else
    {
        while (woEl->next != nullptr)
        {
            woEl = woEl->next;
        }
        woEl->next = initEl;
        return head;
    }
}

/*********
Task 3
*********/

kettenBr* loeschEinMal (kettenBr* m)
{
    while (m != nullptr)
        {
            kettenBr *zuLoesch = m;
            cout << m->ketEl << " ";
            m = m->next;
            delete zuLoesch;
        }
        return m;
}

/*********
Task 4
*********/

double wertDerListeFunk (kettenBr* head)
{
    kettenBr* lesEl = new kettenBr;
    lesEl = head;
    double resulWert;
    if (lesEl == nullptr)
    {
        resulWert = 0;
        return resulWert;
    }
    else if (lesEl->next == nullptr)
    {
        resulWert = lesEl->ketEl;
        return resulWert;
    }
    else{
            resulWert = lesEl->ketEl;
            do{
                lesEl = lesEl->next;
                resulWert = 1/resulWert;
                resulWert = resulWert + lesEl->ketEl;
    } while (lesEl->next != nullptr);
    }
    return resulWert;
}

/***********************************************************************************
For calculating the value of a list, first I reversed the list using this function.
I could have merged this part inside the function of calculation, but
I did not, because of two reasons:
1) To use this function to add another option in the third version, which
   I forgot at the end :)
2) Not to make a messy function
***********************************************************************************/

kettenBr* ordWechsFunk (kettenBr* ordWech, int v)
{
    kettenBr* initElZw = new kettenBr;
    initElZw->ketEl = v;
    initElZw->next = ordWech;
    ordWech = initElZw;
    return ordWech;
}

/*********
Task 5
*********/

kettenBr* nurFuerAuf ()
{
    kettenBr* head4 = new kettenBr;
    head4 = nullptr;
    cout << endl << "continued fraction, enter first value f_0: ";
    int rT;
    int rsQ = 1;
    do
        {
            cin >> rT;
            if ((rT <= 0) && (rsQ > 1))
                {return head4;}
            else
            {
                kettenBr* initEl2 = new kettenBr;
                initEl2->ketEl = rT;
                initEl2->next = nullptr;
                kettenBr* woEl2 = new kettenBr;
                woEl2 = head4;
                if (head4 == nullptr)
                    {
                        head4 = initEl2;
                    }
                else
                    {
                        while (woEl2->next != nullptr)
                        {
                            woEl2 = woEl2->next;
                        }
                        woEl2->next = initEl2;
                    }
            }
                cout << endl << "enter next part denominator f_" << rsQ << " (<=0 for end): ";
                rsQ++;
        } while (0 != 1);
}

/*********************************************************
Some funktions which were used in other two versions
*********************************************************/

void showList (kettenBr* head, int k)
{
    if (head == nullptr){
        cout << "Die Liste ist leer!";
        return;}
    else
    {
            for (int g = 1; g < k; g++){
            cout << head->ketEl << ", ";
            head = head->next;}
            cout << head->ketEl;
        return;
    }
}
int wieGr (kettenBr* head)
{
    int i = 0;
    if (head == nullptr)
        return i;
    else
    {
        do
        {
            i++;
            head = head->next;
        } while (head != nullptr);
        return i;
    }
}

void loeschAllEl(kettenBr* m)
{
            kettenBr *zuLoesch = m;
            cout << m->ketEl << " ";
            m = m->next;
            delete zuLoesch;
}

void loeschEinEl(kettenBr* m)
{
            kettenBr *zuLoesch = m;
            m = m->next;
            delete zuLoesch;
}


/*********
Task 6
*********/

int main()
{
    cout << "Hallo!" << endl;
    cout << endl << "Ich habe drei Koden hier geschrieben. Einer ist genau was im Moodle beschrieben wurde,"
    << endl << "ein anderer ist was mehrere Moeglichkeiten hat, "
    << endl << "und der dritte ist mehr entwickelt worden, soweit ich Lust hatte!"
    << endl << "Welchen Kode moechten Sie jetzt auspruefen?"
    << endl << endl << "1) Die Aufgabe? Dann typen Sie einfach 1"
    << endl << "2) Die bessere Version? Dann typen Sie 2"
    << endl << "3) Die entwickelte? Dann typen Sie 3"
    << endl << "4) Kein Interesse zum Auspruefen? Dann typen Sie einfach eine beliebige Zahl, "
    "ausser von den oben genannten" << endl;
    int o;
    cin >> o;

    if (o == 1)
    {
        do
        {
            kettenBr* head1 = new kettenBr;
            head1 = nullptr;
            head1 = initialFunk(head1, 1);
            head1 = initialFunk(head1, 4);
            head1 = initialFunk(head1, 2);
            head1 = initialFunk(head1, 1);
            head1 = initialFunk(head1, 7);
            kettenBr* head2 = new kettenBr;
            head2 = nullptr;
            head2 = initialFunk(head2, 1);
            head2 = initialFunk(head2, 1);
            head2 = initialFunk(head2, 2);
            head2 = initialFunk(head2, 3);
            kettenBr* head3 = new kettenBr;
            head3 = nullptr;
            kettenBr* ordWech1 = new kettenBr;
            ordWech1 = nullptr;
            kettenBr* tempChan1 = new kettenBr;
            tempChan1 = head1;
            while (tempChan1 != nullptr)
                {
                    ordWech1 = ordWechsFunk(ordWech1, tempChan1->ketEl);
                    tempChan1 = tempChan1->next;
                }
            cout << "cf1 = 123/100 = " << setprecision(zifNachPunkt+1)
            << wertDerListeFunk(ordWech1) << endl;
            while (ordWech1 != nullptr)
            {
                loeschEinEl(ordWech1);
                ordWech1 = ordWech1->next;
            }
            cout << "delete: ";
            head1 = loeschEinMal(head1);

            kettenBr* ordWech2 = new kettenBr;
            ordWech2 = nullptr;
            kettenBr* tempChan2 = new kettenBr;
            tempChan2 = head2;
            while (tempChan2 != nullptr)
                {
                    ordWech2 = ordWechsFunk(ordWech2, tempChan2->ketEl);
                    tempChan2 = tempChan2->next;
                }
            cout << endl << "cf2 = 17/10 = " << setprecision(zifNachPunkt+1)
            << wertDerListeFunk(ordWech2) << endl;
            while (ordWech2 != nullptr)
            {
                loeschEinEl(ordWech2);
                ordWech2 = ordWech2->next;
            }
            cout << "delete: ";
            head2 = loeschEinMal(head2);

            head3 = nurFuerAuf();
            kettenBr* ordWech3 = new kettenBr;
            ordWech3 = nullptr;
            kettenBr* tempChan3 = new kettenBr;
            tempChan3 = head3;
            while (tempChan3 != nullptr)
                {
                    ordWech3 = ordWechsFunk(ordWech3, tempChan3->ketEl);
                    tempChan3 = tempChan3->next;
                }
            cout << "value inputted continued fraction cf3 = " << setprecision(zifNachPunkt+1)
            << wertDerListeFunk(ordWech3) << endl;
            while (ordWech3 != nullptr)
            {
                loeschEinEl(ordWech3);
                ordWech3 = ordWech3->next;
            }
            cout << "delete: ";
            head3 = loeschEinMal(head3);
            cout << endl << endl << "Typen Sie 5 zum Ende des Programms, sonst irgendeine andere Zahl: ";
            int u;
            cin >> u;

            if (u == 5)
                {return 0;}
            } while (0 != 1);
    }

    else if (o == 2)
    {
        kettenBr* head1 = new kettenBr;
        head1 = nullptr;
        head1 = initialFunk(head1, 1);
        head1 = initialFunk(head1, 4);
        head1 = initialFunk(head1, 2);
        head1 = initialFunk(head1, 1);
        head1 = initialFunk(head1, 7);
        kettenBr* head2 = new kettenBr;
        head2 = nullptr;
        head2 = initialFunk(head2, 1);
        head2 = initialFunk(head2, 1);
        head2 = initialFunk(head2, 2);
        head2 = initialFunk(head2, 3);
        kettenBr* head3 = new kettenBr;
        head3 = nullptr;
        cout << "Es gibt schon zwei vorherig initialisierte Listen und eine freie.";
    do
    {
        cout << endl << "Was moechten Sie mit den Listen tun?"
        << endl << endl << "1) Ich moechte die freie Liste ausfuellen."
        << endl << "2) Ich moechte die ganzen Listen loeschen, sodass ich jedes geloeschte Element sehen kann."
        << endl << "3) Den Wert der Listen moechte ich sehen."
        << endl << "4) Oops! Ich habe vergessen, eine Ziffer am Ende der Liste hinzuzufuegen."
        << endl << "5) Einfach den Ausgang will ich!" << endl;
        int u;
        cin >> u;
        if (u == 1)
        {
                cout << endl << "Geben Sie Ihre Liste ein: ";
                int r;
                int ddSS = 1;
                do
                {
                    cin >> r;
                    if ((r <= 0) && (ddSS > 1))
                    {
                        break;
                    }
                    else
                        {
                            head3 = initialFunk(head3, r);
                            cout << endl << "Naechste Ziffer? (0 ist das Ende) ";
                            ddSS++;
                        }
                } while (0 != 1);
        }
        else if (u == 2)
        {
            if (head3 != nullptr){
                cout << endl << "Delete: ";
                while (head1 != nullptr)
                    {
                        loeschAllEl(head1);
                        head1 = head1->next;
                    }
                cout << endl << "Delete: ";
                while (head2 != nullptr)
                    {
                        loeschAllEl(head2);
                        head2 = head2->next;
                    }
                cout << endl << "Delete: ";
                while (head3 != nullptr)
                    {
                        loeschAllEl(head3);
                        head3 = head3->next;
                    }
                cout << endl << "Alle Listen sind bereits geloescht!" << endl;
            }
            else
            {
                cout << endl << "Sie haben noch keine Liste eingegeben. Initialisieren Sie die Liste zuerst!" << endl;
            }
        }
        else if (u == 3)
        {
            kettenBr* ordWech1 = new kettenBr;
            ordWech1 = nullptr;
            kettenBr* tempChan1 = new kettenBr;
            tempChan1 = head1;
            while (tempChan1 != nullptr)
            {
                ordWech1 = ordWechsFunk(ordWech1, tempChan1->ketEl);
                tempChan1 = tempChan1->next;
            }
            cout << endl << "Der Wert ist = " << setprecision(zifNachPunkt+1) << wertDerListeFunk(ordWech1) << endl;
            while (ordWech1 != nullptr)
            {
                loeschEinEl(ordWech1);
                ordWech1 = ordWech1->next;
            }

            kettenBr* ordWech2 = new kettenBr;
            ordWech2 = nullptr;
            kettenBr* tempChan2 = new kettenBr;
            tempChan2 = head2;
            while (tempChan2 != nullptr)
            {
                ordWech2 = ordWechsFunk(ordWech2, tempChan2->ketEl);
                tempChan2 = tempChan2->next;
            }
            cout << endl << "Der Wert ist = " << setprecision(zifNachPunkt+1) << wertDerListeFunk(ordWech2) << endl;
            while (ordWech2 != nullptr)
            {
                loeschEinEl(ordWech2);
                ordWech2 = ordWech2->next;
            }

            kettenBr* ordWech3 = new kettenBr;
            ordWech3 = nullptr;
            kettenBr* tempChan3 = new kettenBr;
            tempChan3 = head3;
            while (tempChan3 != nullptr)
            {
                ordWech3 = ordWechsFunk(ordWech3, tempChan3->ketEl);
                tempChan3 = tempChan3->next;
            }
            cout << endl << "Der Wert ist = " << setprecision(zifNachPunkt+1) << wertDerListeFunk(ordWech3) << endl;
            while (ordWech3 != nullptr)
            {
                loeschEinEl(ordWech3);
                ordWech3 = ordWech3->next;
            }
        }
        else if (u == 4)
        {
            if (head3 != nullptr)
            {
                cout << endl << "Was ist die Ziffer?";
            int zifVer;
            cin >> zifVer;
            if (zifVer != 0)
                {
                    head3 = initialFunk(head3, zifVer);
                    cout << endl << "Alles in Ordnung!" << endl;
                }
            else
                { cout << endl << "Null darf nicht eingegeben werden!" << endl;}
            }
            else
            {
                cout << endl << "Sie haben noch keine Liste eingegeben. Initialisieren Sie die freie Liste zuerst!"
                << endl;
            }
        }
        else if (u == 5)
        {
            return 0;
        }
        else if ((u == 0) || (u > 5))
        {
            cout << "Falsche Zahl!" << endl;
        }

    } while (0 != 1);
    }
    else if (o == 3)
    {
        kettenBr *head = new kettenBr;
        head = nullptr;
        cout << "Willkommen! Die entwickelte Version ist runter." << endl;
    do
    {
        cout << endl << "Was moechten Sie mit der Liste tun?"
        << endl << "1) Die Liste initialisieren?"
        << endl << "2) Die Liste gucken?"
        << endl << "3) Die Groesse der Liste?"
        << endl << "4) Noch eine Ziffer verlassen?"
        << endl << "5) Der Wert der Liste?"
        << endl << "6) Die ganze Liste loeschen?"
        << endl << "7) Ausgang?" << endl;
        int u;
        cin >> u;
        if (u == 1)
            {
                cout << endl << "Geben Sie Ihre Liste ein: ";
                int r;
                int dsW = 1;
                do
                {
                    cin >> r;
                    if ((r <= 0) && (dsW > 1))
                    {
                        break;
                    }
                    else
                        {
                            head = initialFunk(head, r);
                            cout << endl << "Naechste Ziffer? (0 ist das Ende) ";
                            dsW++;
                        }
                } while (0 != 1);
                cout << endl << "Die eingegebene Liste ist: [";
                showList(head, wieGr(head));
                cout << "] mit der Groesse " << wieGr(head) << " Elemente!" << endl;
            }
        else if (u == 2)
        {
            cout << endl << "Die gespeicherte Liste ist: [";
            showList(head, wieGr(head));
            cout << "]" << endl;
        }
        else if (u == 3)
        {
            cout << endl << "Die gespeicherte Liste beinhaltet " << wieGr(head) << " Elemente!" << endl;
        }
        if (u == 4)
        {
            if (head != nullptr)
            {
            cout << endl << "Was ist die Ziffer?";
            int zifVer;
            cin >> zifVer;
            if (zifVer != 0){
            head = initialFunk(head, zifVer);
            cout << endl << "Alles in Ordnung!" << endl;}
            else
            { cout << endl << "Null darf nicht eingegeben werden!" << endl;
            }
            }
            else
            {
                cout << endl << "Sie haben noch keine Liste eingegeben. Initialisieren Sie die Liste zuerst!" << endl;
            }
        }
        else if (u == 5)
        {
            kettenBr* ordWech = new kettenBr;
            ordWech = nullptr;
            kettenBr* tempChan = new kettenBr;
            tempChan = head;
            while (tempChan != nullptr)
            {
                ordWech = ordWechsFunk(ordWech, tempChan->ketEl);
                tempChan = tempChan->next;
            }
            cout << endl << "Der Wert ist = " << setprecision(zifNachPunkt+1) << wertDerListeFunk(ordWech) << endl;
            while (ordWech != nullptr)
            {
                loeschEinEl(ordWech);
                ordWech = ordWech->next;
            }
        }
        else if (u == 6)
        {
        if (head != nullptr)
        {
            while (head != nullptr)
            {
                loeschEinEl(head);
                head = head->next;
            }
            cout << endl << "Die Liste ist geloescht!" << endl;}
            else
            {cout << endl << "Sie haben noch keine Liste eingegeben. Initialisieren Sie die Liste zuerst!" << endl;}
        }
        else if (u == 7)
        {
            return 0;
        }
        else if ((u == 0) || (u > 7))
        {
            cout << "Falsche Zahl!" << endl;
        }
    } while (0 != 1);
    }
    else
    {
        return 0;
    }
}
