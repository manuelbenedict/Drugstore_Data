#include <iostream>
#include "drugstore.h"
#include "medicine.h"
#include "relation.h"
#include "generaloperation.h"

using namespace std;

int main()
{
    void menu();
    int pil;

    string nambat;
    string namtik;
    string Yes;

    apotik aptx;
    adrapt adpt;
    Listapt lapt;

    obat medx;
    admed admd;
    limed limd;

    lire lir;

    createListApt(lapt);
    createListMed(limd);
    createListRel(lir);

    while(pil != 99)
    {
        menu();
        cin >> pil;
        switch (pil)
        {
        case 1 :
            cout << " ===================== " << endl ;
            cout << " TAMBAH APOTIK " << endl ;
            cout << "Masukkan ID apotik : ";
            cin >> aptx.IDapotik;
            cout << "jalan gaesss" <<endl;
            cout << "nama apotik : ";
            cin >> aptx.namaApotik;
            cout << "jalan gaesss" <<endl;
            cout << "nomor izin : ";
            cin >> aptx.noIzin;
            cout << "jalan gaesss" <<endl;
            adpt = alokasiApt(aptx) ;
            cout << "jalan gaesss" <<endl;
            insertLastApt(lapt,adpt) ;
            cout << "jalan gaesss" <<endl;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 2 :
            cout << " ===================== " << endl ;
            cout << " TAMBAH OBAT " << endl ;
            cout << "Masukkan ID obat : ";
            cin >> medx.IDobat;
            cout << "jalan gaesss" <<endl;
            cout << "nama obat : ";
            cin >> medx.namaObat;
            cout << "jalan gaesss" <<endl;
            cout << "harga obat : ";
            cin >> medx.hargaObat;
            cout << "jalan gaesss" <<endl;
            admd = alokasiMed(medx) ;
            cout << "jalan gaesss" <<endl;
            insertLastMed(limd,admd) ;
            cout << "jalan gaesss" <<endl;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 3 :
            cout << " ===================== " << endl ;
            cout << " MENAMBAH OBAT PADA APOTIK TERTENTU " << endl ;
            connect(lir, lapt, limd);
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 4 :
            cout << " ===================== " << endl ;
            cout << " MENGHAPUS OBAT PADA APOTIK TERTENTU " << endl ;
            cout<< "Masukkan nama Apotik : "; cin>>namtik;
            adpt = findElmApt(lapt, namtik);
            while(adpt == NIL){
                cout<<" Mohon maaf apotik tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cin>>namtik;
                    adpt = findElmApt(lapt, namtik);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            cout<< "Masukkan nama Obat : "; cin>>nambat;
            admd = findElmMed(limd, nambat);
            while(admd == NIL){
                cout<<" Mohon maaf obat tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cin>>nambat;
                    admd = findElmMed(limd, nambat);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if(adpt != NIL && admd != NIL){
                disconnectonerel(lir, adpt, admd);
            }else{
                cout<<"Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 5 :
            cout << " ===================== " << endl ;
            cout << " APOTIK TUTUP " << endl ;
            cout << "Masukkan apotik yang ingin ditutup: " ;
            cin >> namtik ;
            admd = findElmMed(limd,namtik) ;
            disconnectmed(lir,admd) ;
            deleteAfterMed(prev(admd),admd) ;
            dealokasiMed(admd) ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 6 :
            cout << " ===================== " << endl ;
            cout << " OBAT YANG PENJUALANNYA DILARANG " << endl ;
            cout << "Masukkan obat yang penjualannya dilarang: " ;
            cin >> nambat ;
            adpt = findElmApt(lapt,nambat) ;
            disconnectapt(lir,adpt) ;
            adrapt Q = findElmApt() ;  /// cara mencari address sebelum obat yang hendak dihapus
            deleteAfterApt(Q,adpt) ;
            dealokasiApt(adpt) ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 7 :
            cout << " ===================== " << endl ;
            cout << " MENCARI NOMOR IZIN APOTIK BERDASARKAN NAMA " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 8 :
            cout << " ===================== " << endl ;
            cout << " MENCARI NOMOR IZIN APOTIK BERDASARKAN ID " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 9 :
            cout << " ===================== " << endl ;
            cout << " MENCARI OBAT " << endl ;
            cout << "Masukkan nama obat: " ;
            cin >> nambat;
            admd = findElmMed(limd,nambat);
            if (admd == NULL)
            {
                cout << "Obat tidak ditemukan" ;
            }
            else
            {
                cout << "ID Obat: " << info(admd).IDobat << " dengan harga: " << info(admd).hargaObat << endl ;
            }
            cout << " ===================== " << endl ;
            cout << endl ;
        case 10 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN APOTIK " << endl ;
            printInfoApt(lapt) ;
            cout << "jalan gaesss" <<endl;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 11 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN OBAT " << endl ;
            printInfoMed(limd) ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 12 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN APOTIK YANG MEMILIKI OBAT TERTENTU " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 13 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN OBAT YANG DIMILIKI APOTIK TERTENTU " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        }

    }
    return 0;
}

void menu()
{
    cout << " =====================SEHAT ASIK JAYA ASRI 4646=====================" << endl ;
    cout << " 1. Tambah apotik DONE " << endl ;
    cout << " 2. Tambah obat DONE " << endl ;
    cout << " 3. Menambah obat pada apotik tertentu HARUSNYA DONE" << endl ;
    cout << " 4. Menghapus obat pada apotik tertentu UDAH (kayaknya)" << endl ;
    cout << " 5. Apotik tutup " << endl ;
    cout << " 6. Obat yang penjualannya dilarang " << endl ;
    cout << " 7. Mencari nomor izin apotik berdasarkan nama " << endl ;
    cout << " 8. Mencari nomor izin apotik berdasarkan ID " << endl ;
    cout << " 9. Mencari obat " << endl ;
    cout << " 10. Menampilkan apotik DONE " << endl ;
    cout << " 11. Menampilkan obat DONE " << endl ;
    cout << " 12. Menampilkan apotik yang memiliki obat tertentu " << endl ;
    cout << " 13. Menampilkan obat yang dimiliki apotik tertentu " << endl ;
    cout << " 99. Exit " << endl ;
    cout << " Pilih menu : " ;
    cout<< endl ;
}
