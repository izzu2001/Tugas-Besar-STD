#include "artikel.h"

void createlistArtikel(listArtikel &A){
    first_a(A) = NULL;
}

void createlistTag(listTag &T){
    first_t(T) = NULL;
}

adrArtikel createArtikel(infoArtikel newinfo){
    adrArtikel P = new artikel;
    info(P) = newinfo;
    first_r(P) = NULL;
    next(P) = NULL;

    return P;
}

adrTag createTag(string nama, string tipe){
    adrTag P = new tag;
    info(P).nama_tag = nama;
    info(P).tipe = tipe;
    next(P) = NULL;

    return P;
}

adrRelasi createRelasi(adrTag P){
    adrRelasi R = new relasi;
    info(R) = P;
    next(R) = NULL;

    return R;
}

adrArtikel cariArtikel(infoArtikel cari, listArtikel A){
    if(first_a(A)==NULL){
        return NULL;
    }else{
        adrArtikel P = first_a(A);
        while(next(P)!=NULL && info(P)!=cari){
            P = next(P);
        }
        if(info(P)==cari){
            return P;
        }else{
            return NULL;
        }
    }
}

void insertArtikel(infoArtikel n, listArtikel &A){
    adrArtikel P = createArtikel(n);
    if(first_a(A)==NULL){
        first_a(A) = P;
    }else{
        adrArtikel Q = first_a(A);
        while(next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteFirstArtikel(listArtikel &A, adrArtikel &P){
    if(first_a(A)==NULL){
        cout<<"Tidak Ada Artikel"<<endl;
    }else{
        P = first_a(A);
        first_r(P) = NULL;
        first_a(A) = next(P);
        next(P) = NULL;
    }
}

void deleteAfterArtikel(listArtikel &A, adrArtikel prec, adrArtikel &P){
    P = next(prec);
    next(prec) = next(P);
    first_r(P) = NULL;
    next(P) = NULL;
}

void deleteArtikel(infoArtikel nama_Artikel, listArtikel &A){
    adrArtikel temp; adrArtikel prec;
    adrArtikel P = cariArtikel(nama_Artikel,A);
    if(P==NULL){
        cout<<"Tag Tidak Tersedia"<<endl;
    }else{
        if(P==first_a(A)){
            deleteFirstArtikel(A,prec);
        }else{
            prec = first_a(A);
            while(next(prec)!=P){
                prec = next(prec);
            }
            deleteAfterArtikel(A,prec,temp);
        }
    }
}

adrTag cariTag(string nama_tag, listTag T){
    if(first_t(T)==NULL){
        return NULL;
    }else{
        adrTag P = first_t(T);
        while(next(P)!=NULL && info(P).nama_tag!=nama_tag){
            P = next(P);
        }
        if(info(P).nama_tag==nama_tag){
            return P;
        }else{
            return NULL;
        }
    }
}

void insertTag(string nama_tag, string tipe, listTag &T){
    adrTag P = createTag(nama_tag,tipe);
    if(first_t(T)==NULL){
        first_t(T) = P;
    }else{
        next(P) = first_t(T);
        first_t(T) = P;
    }
}

void deleteFirstTag(listTag &T, adrTag &P){
    if(first_t(T)==NULL){
        cout<<"Data Tag Kosong"<<endl;
    }else{
        P = first_t(T);
        first_t(T) = next(P);
        next(P) = NULL;
    }
}

void deleteAfterTag(listTag &T, adrTag prec, adrTag &P){
    P = next(prec);
    next(prec) = next(P);
    next(P) = NULL;
}

void deleteTag(string nama_tag, listTag &T){
    adrTag temp; adrTag prec;
    adrTag P = cariTag(nama_tag, T);
    if(P==NULL){
        cout<<"Tag Tidak Tersedia"<<endl;
    }else{
        if(P==first_t(T)){
            deleteFirstTag(T,prec);
        }else{
            prec = first_t(T);
            while(next(prec)!=P){
                prec = next(prec);
            }
            deleteAfterTag(T,prec,temp);
        }
    }
}

void insertLastRelasi(adrRelasi P, adrArtikel A){
    adrRelasi Q;
    if(first_r(A)==NULL){
        first_r(A) = P;
    }else{
        Q = first_r(A);
        while(next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void relasiArtikelTag(listArtikel A, listTag T, infoArtikel artikel, string nama_Tag){
    adrArtikel P; adrTag Q;
    if(first_a(A)!=NULL && first_t(T)!=NULL){
        P = cariArtikel(artikel, A);
        Q = cariTag(nama_Tag,T);
        if(P!=NULL && Q!=NULL){
            adrRelasi R = createRelasi(Q);
            insertLastRelasi(R,P);
        }else{
            cout<<"Artikel atau Tag tidak tersedia"<<endl;
        }
    }else{
        cout<<"Data Kosong"<<endl;
    }
}

void showAll(listArtikel A){
    if(first_a(A)!=NULL){
        adrArtikel P = first_a(A);

        while(P!=NULL){
            cout<<"Artikel "<<info(P)<<" Punya Tag :"<<endl;
            adrRelasi Q = first_r(P);
            while(Q!=NULL){
                cout<<info(info(Q)).nama_tag<<" bertipe "<<info(info(Q)).tipe<<endl;
                Q = next(Q);
            }
            cout<<endl;
            P = next(P);
        }
    }else{
        cout<<"Data Kosong"<<endl;
    }
}

void showMostUsedTag(listArtikel A, listTag T){
    if(first_a(A)!=NULL && first_t(T)!=NULL){
        adrTag P = first_t(T);
        adrTag Max;
        int counter = 0;
        int max = 0;
        while(P!=NULL){
            adrArtikel Q = first_a(A);
            while(Q!=NULL){
                if(P==adrTag(Q)){
                    counter++;
                }
                Q = next(Q);
            }
            if(counter>max){
            max = counter;
            Max = P;
            }
            P = next(P);
        }
        cout<<endl;
        cout<<"Tag terbanyak yang digunakan oleh Artikel adalah "<<info(Max).nama_tag<<"\t"<<endl;
    }else{
        cout<<"Data Kosong"<<endl;
    }
}

/*void sameTagTipeArtikel(listArtikel A, listTag T, string tag){
    adrRelasi Q = first_r(T);
    if(Q!=NULL){
        adrTag P = cariTag(tag,T);
        cout<<"Tag"<<tag.nama_tag<<" dimiliki oleh Artikel "<<endl;
        while(P!=NULL){
            cout<<"Artikel "<<artikel(info)<<endl;
            P = next(P);
        }
    }else{
        cout<<"Tag tidak tersedia"<<endl;
    }
    cout<<endl;
}*/

void showWhichTagArtikel(listArtikel A, listTag T, string tipe){
    if(first_a(A)!=NULL){
        adrArtikel P = first_a(A);
        while(P!=NULL){
            adrRelasi Q = first_r(P);
            while(Q!=NULL){
                if(info(info(Q)).tipe==tipe){
                    cout<<"Artikel "<<info(P)<<" Mempunyai Tag "<<info(info(Q)).nama_tag<<" Bertipe "<<tipe<<endl;
                }
                Q = next(Q);
            }
            P = next(P);
        }
    }else{
        cout<<"Data Kosong"<<endl;
    }
    cout<<endl;
}

void showArtikel(listArtikel A){
    adrArtikel P = first_a(A);
    while(P!=NULL){
        cout<<info(P)<<endl;
        P = next(P);
    }
}

void showTag(listTag T){
    adrTag P = first_t(T);
    while(P!=NULL){
        cout<<info(P).nama_tag<<" Bertipe "<<info(P).tipe<<endl;
        P = next(P);
    }
}
