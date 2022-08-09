#include <stdio.h>
struct reservation{
    char name[110];
    int tedad;
    int salon;
    int x[20];
    int y[20];
    int pass;
}s[100];
int password=1234;
int salon1[4][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
int k=0;
int salon2[4][10]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void menu();
void vaziat();
void reserve();
void cancel();
void gozaresh();
int main(){
    menu();
    return 0;}
void menu(){
    int n;
    do {
        printf("please select from the menu:\n");
        printf("1.vaziat salon\n");
        printf("2.reserve ticket\n");
        printf("3.canceling ticket\n");
        printf("4.gozaresh e reservi ha\n");
        printf("5.exit\n");
        scanf("%d",&n);
        if(n==1){vaziat();}
        if(n==2){reserve();
        }
        if(n==3){cancel();}
        if(n==4){gozaresh();}
        if(n==0){break;}
    } while (n!=5);
}
void vaziat(){
    int n1;
    do {
        printf("press 1 for salon 1\n");
        printf("press 2 for salon 2\n");
        printf("press 0 for menu\n");
        scanf("%d", &n1);
        switch (n1) {
            case 1:{
                printf("avalable seat = 0 \t  not avalable seat=1\n");
                for (int i = 0; i < 4; i++) {
                    printf("\n");
                    for(int j = 0; j < 10; j++) {
                        printf("%d \t ",salon1[i][j]);
                    }
                }
                printf("\n");
                break;

                case 2:
                    printf("avalable seat = 0 \t  not avalable seat=1\n");
                for (int i = 0; i < 4; i++) {
                    printf("\n");
                    for (int j = 0; j < 10; j++) {
                        printf("%d\t",salon2[i][j]);
                    }
                }
                printf("\n");
                break;
                case 0:
                    menu();
                break;
            }

        }
    } while (n1!=4);
}
void reserve(){
    int r;
    do{
        printf("enter 1 for reserving in salon 1:\n");
        printf("enter 2 for reserving in salon 2:\n");
        printf("enter 0 back to menu:\n");
        scanf("%d",&r);
        if(r==1){
            k++;
            printf("enter your name:\n");
            scanf("%s",&s[k].name);
            printf("lotfan tedad blit ha ra vared konid:\n");
            scanf("%d",&s[k].tedad);
            printf("geymat blit ha:%d\n",s[k].tedad*(50));
            for (int i = 0; i < s[k].tedad; i++) {
                printf("enter seat s x from 0 to 3:\n");
                scanf("%d",&s[k].x[i]);
                printf("enter seat s y from 0 to 9:\n");
                scanf("%d",&s[k].y[i]);
                s[k].salon = 1;
                salon1[s[k].x[i]][s[k].y[i]] = 1;
                printf("blit ha ba movafaghiat reserv shod.\n");
                printf("your reservation id is:%d\n",k);

            }
            printf("enter a 4 digit password:\n");
            scanf("%d",&s[k].pass);
        }
        else if(r==2){
            k++;
            printf("enter your name:\n");
            scanf("%s",&s[k].name);
            printf("lotfan tedad blit ha ra vared konid:\n");
            scanf("%d",&s[k].tedad);
            int gheymat;
            printf("geymat blit ha:%d\n",s[k].tedad*(50));
            for (int i = 0; i < s[k].tedad; i++) {
                printf("enter seat s x from 0 to 3:\n");
                scanf("%d",&s[k].x[i]);
                printf("enter seat s y from 0 to 9:\n");
                scanf("%d",&s[k].y[i]);
                s[k].salon = 2;
                salon2[s[k].x[i]][s[k].y[i]] = 1;
                printf("blit ha ba movafaghiat reserv shod.\n");
                printf("your reservation id is:%d\n",k);

            }
            printf("enter a 4 digit password:\n");
            scanf("%d",&s[k].pass);
        }
        else if(r==0){
            menu();
        } else printf("meghdar na moshakhas\n lotfsn dobare talash konid.\n");

    } while (r!=4);
}
void gozaresh(){
    int n4;
    do {
        printf("1. namayesh naam ha va blit ha.\n");
        printf("0.back to menu.\n");
        scanf("%d",&n4);
        if(n4==1) {
            int ramz;
            printf("lotfan password ra vared konid:\n");
            scanf("%d",&ramz);
            switch (ramz) {
                int id;
                case 1234:

                    printf("reservation id ra vared konid:\n");
                    scanf("%d",&id);
                    printf("name:%s\n", s[id].name);
                    printf("salon:%d\n",s[id].salon);
                    printf("blit ha:\n");
                    for (int j = 0; j < s[id].tedad; j++) {
                        printf("%d", s[id].x[j]);
                        printf("%d", s[id].y[j]);
                        printf("\n");
                    }
                    break;
                default:
                    printf("password sahih nist.\n");
                    printf("lotfan dobare talash konid.\n");
                    break;
            }
        }
        if(n4==0){menu();}
    } while (n4!=3);
}
void cancel(){
    int x4;
    int idd;
    int passs;
    do {
        printf("lotfan baraye canceli blit 1 ra vared konid.\n");
        printf("baraye bazgasht b menu 0 ra vared konid.\n");
        scanf("%d",&x4);
        switch (x4) {
            case 1:
                printf("lotfan id ra vared konid.\n");
                printf("lotfan password khod ra vared konid\n");
                scanf("%d",&idd);
                scanf("%d",&passs);
                if(passs==s[idd].pass){
                    for (int i = 0; i < s[idd].tedad; i++) {
                        for (int j = 0; j < s[idd].tedad; ++j) {
                            if(s[idd].salon==1){
                                salon1[s[idd].x[i]][s[idd].y[j]]=0;
                                s[idd].x[i]=NULL;
                                s[idd].y[j]=NULL;
                            }
                            if(s[idd].salon==2){
                                salon2[s[idd].x[i]][s[idd].y[j]]=0;
                                s[idd].x[i]=NULL;
                                s[idd].y[j]=NULL;
                            }

                        }

                    }
                    printf("blit ha ba movafaghiat cancel shod.\n");
                }
                break;
            case 0:menu();break;
        }
    } while (x4!=3);
}
