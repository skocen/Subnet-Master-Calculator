#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <bitset>
#include <cmath>
using namespace std;
void maskubin(int n, int mask[]){
    int okt=0;
        for(int i=1;i<=32;i++){
            if(n>0)
                mask[okt]=mask[okt]*10+1;
            else
                mask[okt]*=10;
            if(i%8==0) okt++;
            n--;
}
}
int bintodec(int x){
    int dec=0,b=1;
    while(x>0){
        dec+=x%2*b;
        b*=2;
        x/=10;
    }
    return dec;
}
int main(void){
system("Color A");
int broj[4]={0,0,0,0};
string naredba;
printf("Master Subnet Calculator\nby Sebastijan Kocen\nUvod u racunalne mreze\nVisoko uciliste Algebra\n");
UNOS:cout<<endl<<">";
cin>>naredba;
std::transform(naredba.begin(), naredba.end(), naredba.begin(), ::tolower);
BINDEC:if(naredba=="bintodec"){
    cout<<"Upisite adresu u binarnom zapisu:";
    int dec[4]={0,0,0,0};
    scanf("%d.%d.%d.%d",&broj[0],&broj[1],&broj[2],&broj[3]);
    for(int i=0;i<4;i++)
        dec[i]=bintodec(broj[i]);
    if(dec[0]>255||dec[1]>255||dec[2]>255||dec[3]>255){
        cout<<"Unos je izvan granica, jedan ili vise okteta su veci od 255. Ponovo upisite adresu."<<endl;
        goto BINDEC;
    }
    else printf("\nAdresa u dekadskom zapisu:%d.%d.%d.%d\n",dec[0],dec[1],dec[2],dec[3]);
}
DECBIN:if(naredba=="dectobin"){
    cout<<"Upisite adresu u dekadskom zapisu:";
    scanf("%d.%d.%d.%d",&broj[0],&broj[1],&broj[2],&broj[3]);
    if(broj[0]>255 || broj[1]>255 || broj[2]>255 || broj[3]>255){
        cout<<"Unos je izvan granica, jedan ili vise okteta su veci od 255. Ponovo upisite adresu."<<endl;
        goto DECBIN;
    }
    else {
         bitset<8>bin0(broj[0]);
         bitset<8>bin1(broj[1]);
         bitset<8>bin2(broj[2]);
         bitset<8>bin3(broj[3]);
    cout<<"Adresa u binarnom zapisu:"<<bin0<<"."<<bin1<<"."<<bin2<<"."<<bin3<<endl;
    }
}
MASK:if (naredba=="mask"){
    int n;
    cout<<"Upisite masku: /";
    cin>>n;
    if(n>32 || n<2){
        cout<<"Unos izvan granica, maska je u rasponu 2-32. Ponovno unesite masku."<<endl;
        goto MASK;
    }
    else{
        int mask[4]={0,0,0,0};
        maskubin(n,mask);
        printf("\nMaska binarno:%08d.%08d.%08d.%08d",mask[0],mask[1],mask[2],mask[3]);
        printf("\nMaska decimalno:%d.%d.%d.%d\n",bintodec(mask[0]),bintodec(mask[1]),bintodec(mask[2]),bintodec(mask[3]));
      }
}
WHAT:if (naredba=="whatmask"){
    long double n,maskdouble;
    int mask;
    cout<<"Broj korisnika:";
    cin>>n;
    if(n>(pow(2,32)-2)){
        cout<<"Preveliki zahtjev. Ponovno upisite broj korisnika."<<endl;
        goto WHAT;
    }
    else{
    maskdouble=32-log2(n+2);
    mask=maskdouble;
    cout<<"Najmanja maska je /"<<mask<<endl;
    }
}
HOST:if(naredba=="hostnumber"){
    int mask;
    double broj;
    cout<<"Upisite masku: /";
    cin>>mask;
    if(mask>32 || mask<2){
        cout<<"Unos izvan granica, maska je u rasponu 2-32. Ponovno unesite masku."<<endl;
        goto HOST;
    }
    else {
        broj=pow(2,32-mask)-2;
        int n=broj;
        cout<<"Broj hostova:"<<n<<endl;
    }
}
SUB:if(naredba=="subnetnumber"){
    char klasa;
    int  k,mask;
    cout<<"Upisite masku: /";
    cin>>mask;
    if(mask>32 || mask<2){
        cout<<"Unesena maska je izvan granica. Ponovo upisite masku."<<endl;
        goto SUB;
    }
    cout<<"Upisite klasu(A,B,C):";
    cin>>klasa;
    klasa=tolower(klasa);
    if(klasa=='a') k=8;
    else if(klasa=='b') k=12;
    else if(klasa=='c') k=16;
    else {
        cout<<"Nevaljan unos. Pokusajte ponovo."<<endl;
        goto SUB;
    }
    if((mask-k)>0){
        int subnet;
        double snet;
        snet=pow(2,mask-k);
        subnet=snet;
        cout<<"Broj subneta:"<<subnet;
    }
    else{
        cout<<"Podjela mreze u subnete nije moguca. Pokusajte ponovo."<<endl;
        goto SUB;
    }
}
NETWORK:if(naredba=="network"){
    cout<<"Upisi IP adresu:";
    scanf("%d.%d.%d.%d",&broj[0],&broj[1],&broj[2],&broj[3]);
    if(broj[0]>255 || broj[1]>255 || broj[2]>255 || broj[3]>255){
        cout<<"Unos je izvan granica, jedan ili vise okteta su veci od 255. Ponovo upisite adresu."<<endl;
        goto NETWORK;
    }
    int mask[4]={0,0,0,0},n,net[4];
    MASKICA:cout<<"Upisi masku: /";
    cin>>n;
    if(n>32 || n<2){
        cout<<"Unos izvan granica, maska je u rasponu 2-32. Ponovno unesite masku."<<endl;
        goto MASKICA;
    }
    else{
        maskubin(n,mask);
    unsigned char broadcast[4];
    for(int i=0;i<4;i++) mask[i]=bintodec(mask[i]);
    for(int i=0;i<4;i++) net[i]=mask[i]&broj[i];
    cout<<endl<<"Adresa mreze:"<<net[0]<<"."<<net[1]<<"."<<net[2]<<"."<<net[3]<<endl;
    cout<<"Prva korisna:"<<net[0]<<"."<<net[1]<<"."<<net[2]<<"."<<net[3]+1<<endl;
    for(int i=0;i<4;i++) broadcast[i]=net[i]|(~mask[i]);
    printf("Zadnja korisna:%hhu.%hhu.%hhu.%hhu",broadcast[0],broadcast[1],broadcast[2],broadcast[3]-1);
    printf("\nBroadcast:%hhu.%hhu.%hhu.%hhu\n",broadcast[0],broadcast[1],broadcast[2],broadcast[3]);
}
}
if(naredba=="summarise"){
    int n, mreze[999][5],sumip[4],mask;
    cout<<"Broj mreza:";
    cin>>n;
    cout<<"Upisite IP adrese i pripadajucu masku (x.x.x.x/m) u rastucem poretku"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<". mreza:";
        UPIS:scanf("%d.%d.%d.%d/%d",&mreze[i][0],&mreze[i][1],&mreze[i][2],&mreze[i][3],&mreze[i][4]);
        if(mreze[i][0]>255||mreze[i][1]>255||mreze[i][2]>255||mreze[i][3]>255||mreze[i][4]>32)
        {
            cout<<"Neispravan unos. Ponovo upisite prijasnju mrezu."<<endl;
            goto UPIS;
        }
    }
    for(int i=0;i<4;i++)
        sumip[i]=mreze[0][i];
    for(int i=1;i<n;i++){
        sumip[1]=sumip[1]&mreze[i][1];
        sumip[2]=sumip[2]&mreze[i][2];
        sumip[3]=sumip[3]&mreze[i][3];
    }
    if(mreze[0][1]!=mreze[n-1][1])
        mask=32-(log2(mreze[n-1][1]-mreze[0][1])+1+16);
    else{
        if(mreze[0][2]!=mreze[n-1][2])
            mask=32-(log2(mreze[n-1][2]-mreze[0][2])+1+8);
        else
            mask=32-(log2(mreze[n-1][3]-mreze[0][3])+1);
    }
    cout<<endl<<"Sumarna mreza:"<<sumip[0]<<"."<<sumip[1]<<"."<<sumip[2]<<"."<<sumip[3]<<"/"<<mask<<endl;

}
SUBNETI:if(naredba=="subnet"){
    int n,zahtjevi[10],maske[10],adrese[10][2],sum=0;
    cout<<"Upisite broj subneta:";
    cin>>n;
    if(n>pow(2,16)){
        cout<<"Nije moguce ispuniti Vase zahtjeve. Pokusajte ponovo subnetirati mrezu."<<endl;
        goto SUBNETI;
    }
    for(int i=0;i<n;i++){
        printf("Upisite broj racunala u %d. ucionici:",i+1);
        cin>>zahtjevi[i];
        sum+=zahtjevi[i];
    }
    if(sum>65534){
        cout<<"Nije moguce ispuniti Vase zahtjeve. Pokusajte ponovo subnetirati mrezu."<<endl;
        goto SUBNETI;
    }
    else{
    sort(zahtjevi,zahtjevi+n);
    reverse(zahtjevi,zahtjevi+n);
    cout<<endl;
    for(int i=0;i<n;i++){
        maske[i]=32-log2(zahtjevi[i]+2);
        if(i==0){
            adrese[i][0]=0;
            adrese[i][1]=0;
        }
        else{
        if(maske[i]<25)
             adrese[i][0]=adrese[i-1][0]+pow(2,24-maske[i-1])-1;
        else
            adrese[i][0]=adrese[i-1][0];
        adrese[i][1]=adrese[i-1][1]+pow(2,32-maske[i-1]);
        if(adrese[i][1]>255){
            adrese[i][1]=0;
            adrese[i][0]++;
        }
        }
        printf("Zahtjev:%d racunala Mreza:192.168.%d.%d/%d\n",zahtjevi[i],
         adrese[i][0],adrese[i][1],maske[i]);
    }
    }
}
goto UNOS;
}
