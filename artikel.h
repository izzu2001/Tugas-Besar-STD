#ifndef ARTIKEL_H_INCLUDED
#define ARTIKEL_H_INCLUDED

#include <iostream>
#include <string>

#define info(P) P->info
#define next(P) P->next
#define first_a(P) P.first_a
#define first_t(P) P.first_t
#define first_r(P) P->first_r

using namespace std;

typedef string infoArtikel;
struct infoTag{
    string nama_tag;
    string tipe;
};
typedef struct artikel *adrArtikel;
typedef struct tag *adrTag;
typedef struct relasi *adrRelasi;

struct artikel{
    infoArtikel info;
    adrArtikel next;
    adrRelasi first_r;
};

struct relasi{
    adrRelasi next;
    adrTag info;
};

struct tag{
    infoTag info;
    adrTag next;
};

struct listArtikel{
    adrArtikel first_a;
};

struct listTag{
    adrTag first_t;
};

void createlistArtikel(listArtikel &A);
void createlistTag(listTag &T);
adrArtikel createArtikel(infoArtikel newinfo);
adrTag createTag(string nama, string tipe);
adrRelasi createRelasi(adrTag P);
adrArtikel cariArtikel(infoArtikel cari, listArtikel A);
void insertArtikel(infoArtikel n, listArtikel &A);
void deleteFirstArtikel(listArtikel &A, adrArtikel &P);
void deleteAfterArtikel(listArtikel &A, adrArtikel prec, adrArtikel &P);
void deleteArtikel(infoArtikel nama_Artikel, listArtikel &A);
adrTag cariTag(string nama_tag, listTag T);
void insertTag(string nama_tag, string tipe, listTag &T);
void deleteFirstTag(listTag &T, adrTag &P);
void deleteAfterTag(listTag &T, adrTag prec, adrTag &P);
void deleteTag(string nama_tag, listTag &T);
void insertLastRelasi(adrRelasi P, adrArtikel A);
void relasiArtikelTag(listArtikel A, listTag T, infoArtikel artikel, string nama_tag);
void showAll(listArtikel A);
void showMostUsedTag(listArtikel A, listTag T);
void sameTagTipeArtikel(listArtikel A, listTag T, string tipe);
void showWhichTagArtikel(listArtikel A, listTag T, string tipe);
void showArtikel(listArtikel A);
void showTag(listTag T);

#endif // ARTIKEL_H_INCLUDED
