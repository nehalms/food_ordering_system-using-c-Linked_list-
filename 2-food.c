#include<stdio.h>

#include<stdlib.h>

#include<math.h>

#include<string.h>

#include<conio.h>

#include<ctype.h>

#include<time.h>

#include<malloc.h>

#include <unistd.h>

#include <dos.h>

#define MALLOC(p,s,t)\
{\
    p = (t)malloc(s);\
    if(p == NULL)\
    {\
    printf("Insufficient memory\n");\
    exit(1);\
    }\
}

struct food
{
    int num;
    char name[100];
    float price;
    int quantity;
    struct food *link;
};
typedef struct food *NODE;

char username[50][100] = {0},phno[20] = {0};
int item_count = 0,list_count = 15,u = 0;
int array[30],a_num = 0,cartflag = 0;
int deleteflag = 0;
int bfastnum,quant, *rear=-1, *front=0;
NODE cart_items = NULL;
NODE f = NULL;
NODE second;
NODE start = NULL;
NODE first,printcart = NULL;
int cart_count = 0;
int temp_num,billflag = 0,payflag = 0,proceedflag = 0,endflag = 0,editflag = 0,altpriceflag = 0,totpriflag = 0,adminorderflag = 0,nxtusrflag = 0;
float total = 0;
NODE tfood;
char food[100][100] = {"PLAIN_DOSA","MASALA_DOSA","POORI","IDLI","CHAPATHI","UPMA","PONGAL","COFFEE","TEA","VEG_SANDWICH","LEMON_RICE","PALAV","FRIED_RICE","SOUTH_INDIAN_MEALS","NORTH_INDIAN_MEALS"};
int pricef[100] = {35,45,35,25,35,30,30,12,12,40,35,38,40,60,70};
char str1[100][100] = {"PHONE PE","GOOGLE PAY","PAYTM"};
char str2[100][100] = {"CREDIT CARD","DEBIT CARD"};
int msleep(unsigned int tms) {
  return usleep(tms * 1000);
}

reset()
{
   printf("\033[0m");
}

red()
{
   printf("\033[0;31m");
}

cyan()
{
   printf("\033[0;36m");
}

yellow()
{
   printf("\033[0;33m");
}

blue()
{
   printf("\033[0;34m");
}

green()
{
   printf("\033[0;32m");
}


int main()
{
    int a;
    char str[100][100] = {"Admin", "User"};
    if(cartflag == 0)
    {
        food_list();
    }
    
    while(1)
    {
        system("cls");
        printf("\n------------------------------------------------------------------\n");
        printf("\n-----------------   ");
        cyan();
        printf("FOOD DELIVERY SYSTEM   ");
        reset();
        printf("-----------------------\n");
        printf("\n------------------------------------------------------------------\n");
            
        do
        {
            printf("\n[1] -> %s\n",str[1]);

            printf("\n[2] -> %s\n",str[0]); 

            printf("\n[0] -> EXIT\n");

            printf("\nEnter : ");
            yellow();
            scanf("%d",&a);
            reset();

            if(a>2)
            {
                red();
                printf("\nInvalid\n");
                reset();
            }
        

        switch(a)
        {
            case 2:
                admin();
                break;
        
            case 1:
                user();
                break;
            
            case 0 : exit(1);
        }
        }while(a>2);
    }
    return 0;
}

void user()
{
    int b,ii;
    cartflag = 1;
    char gar[30];
    system("cls");
    gets(gar);
    printf("\nYour Sweet Name Please : ");
    yellow();
    gets(username[u++]);
    reset();
    printf("\n\n");
    printf("Phone Number : ");
    yellow();
    gets(phno);
    reset();
    while(1)
    {
        do
        {
            system("cls");
            time_t t;  
            time(&t);
            cyan();
            printf("\nWelcome  ");
            puts(username);
            reset();
            printf("\n");
            yellow();
            printf("!! ");
            reset();
            green();
            printf("Customer is king, king never bargains");
            reset();
            yellow();
            printf(" !!\n");
            reset();
            green();
            printf("\n%s\n", ctime(&t));
            reset();
            printf("\n----- Tool Bar -----\n");
            printf("\n [1] -> Food Menu\n");
            printf("\n [2] -> Cart\n");
            printf("\n [3] -> Proceed to Order\n");
            printf("\n [0] -> BACK\n");
            
            printf("\n  Enter : ");
            yellow();
            scanf("%d",&b);
            reset();

            if(b>3)
            {
                red();
                printf("\n Invalid\n");
                getch();
                reset();
            }
        }while(b>3);
        switch (b)
        {
        case 1: 
                food_order();
                break;
        case 2: 
                cart();
                break;
        case 3: 
                proceed();
                if(endflag == 1)
                    return;
                break;
        //case 4: 
               // bill();
               // break;
        case 0: 
                main();
        }
    }
    return;
}

void food_order()
{
    int flag = 0;
    int ar = item_count;
    proceedflag = 1;
    if(payflag == 1)
    {
        nxtusrflag = 1;
    }
        do
        {
            printf("\n -------------------------------- ");
            cyan();
            printf("MENU ");
            reset();
            printf("----------------------------------------\n");
            cyan();
            printf("\n Sl.no \t \t \t \t Food Name \t \t \t\tprice - 0.00/-\n");
            reset();
            printf(" -------------------------------------------------------------------------------------");
            NODE q = first;
            NODE temp;
            while(q != NULL)
            {
                //printf("\n  %d \t \t \t \t %.20s \t \t \t \t \t  %.2f\n",q->num,q->name,q->price);
                printf("\n  %d\t\t\t\t%s",q->num,q->name);
                spacing(q->name,q->price,40);
                printf("%0.2f\n", q->price);
                q = q->link; 
                msleep(20);
            }

            if(altpriceflag == 1)
            {
                altpriceflag = 0;
                return;
            }

            if(deleteflag == 1)
            {
                deleteflag = 0;
                return;
            }
            
            printf("\n Food Sl.No : ");
            yellow();
            scanf("%d",&bfastnum);
            reset();
            if(bfastnum>list_count || bfastnum == 0)
            {
                red();
                printf(" Invalid");
                reset();
                getch();
                continue;
            }
            q = first;
            int doub_quant = 0;
            for(int l=0;l<30;l++)
            {
                if(bfastnum == array[l])
                {
                    doub_quant = 1;
                }
            }
            if(doub_quant == 0)
            {
                array[a_num++] = bfastnum;
            }
            
            while(q != NULL)
            {
                if(bfastnum == q->num)
                {
                    printf("\n Food Name : ");
                    green();
                    printf("%s",q->name);
                    reset();
                    temp = q;
                }
                q = q->link;
            }
            printf("\n Quantity: ");
            yellow();
            scanf("%d",&quant);
            reset();
            if(doub_quant == 1)
            {
                temp->quantity+=quant;
            }
            else{
                temp->quantity = quant;
            }

            item_count++;
            cart_count = item_count;
            green();
            printf("\n Added to cart\n");
            reset();
            printf("\n Order more(1/0)?\n");
            printf(" ");
            yellow();
            scanf("%d",&flag);
            reset();
        }while(flag == 1);
}

void cart()
{
    int slno = 1,totalflag;
    if(billflag == 1)
    {
        endflag = 0;
    }
    if(nxtusrflag == 1)
    {
        payflag = 0;
    }
    if(array[0] == NULL || payflag == 1)
    {
        red();
        printf("\nCart is Empty\n");
        reset();
        getch();
        return;
    }
    temp_num = a_num;
    printf("-------------------------------------------------");
    cyan();
    printf(" CART ");
    reset();
    printf("-----------------------------------------------------");
    cyan();
    printf("\nsl.no\t \tItemcode\t\tItem\t\t\t Quantity\t Price\t \t   Total\n");
    reset();
    printf("-------------------------------------------------------------------------------------------------------------");
    
    do
    {
        NODE cur = first;   
        int it_num = array[temp_num--];
        
        while(cur != NULL)
        {
            if(it_num == cur->num)
            {
                cartflag = 1;
                //printf("\n%d\t\t %d\t\t\t%s \t\t\t    %d \t       %.2f\t %.2f\n",slno,cur->num,cur->name,cur->quantity,cur->price,cur->price * cur->quantity);
                printf("\n%d\t\t  ",slno);
                printf("%d\t\t\t%s",cur->num,cur->name);
                spacing(cur->name,cur->price,28);
                printf("%d\t\t ",cur->quantity);
                printf("%0.2f\t\t   ",cur->price);
                printf("%0.2f\n",cur->quantity*cur->price);
                slno++;
                item_count--;       
                msleep(50);
            }
            cur = cur->link;
        }
    }while(temp_num>=0);


    totpriflag = 1;
    int a = a_num;
    total = 0;
    do
    {
        NODE c = first;   
        int pop = array[a--];

        while(c != NULL)
        {
            if(pop == c->num)
            {
                total += c->price * c->quantity; 
            }
            c = c->link;
        }
    }while(a>=0);

    
    if(adminorderflag == 1)
    {
        return;
    }

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\n                                                                     TOTAL : ");
    green();
    printf("%.2f\n",total);
    reset();

    if(editflag == 1)
    {
        editflag = 0;
        return;
    }

    if(billflag == 1)
    {
        billflag = 0;
        return;
    }
    //getch();
    int back;
    do
    {
        printf("\n[1] -> EDIT CART\n");
        printf("[0] -> BACK\n");
        printf("\n Enter : ");
        yellow();
        
        scanf("%d",&back);
        reset();
        if(back >1)
        {
            red();
            printf("Invalid\n");
            reset();
        }
        if(back == 1)
        {
            edit();
            cart();
        }
    }while(back>1);
    return;
}


void food_list()
{
    for(int i=0;i<list_count;i++)
    {
        NODE temp;
        MALLOC(temp,sizeof(struct food),NODE);
        temp->num = i+1;
        strcpy(temp->name,food[i]);
        temp->price = pricef[i];
        temp->link = NULL;
        if(f == NULL)
        {
            f = temp;
            first = f;
        }
        else
        {
            while(f->link!=NULL)
            {
                f = f->link;
            }
            f->link = temp;
        }
    } 
}


void proceed()
{
    if(payflag == 1 || array[0] == NULL)
    {
        red();
        printf("\nAdd items to cart\n");
        reset();
        printf("------------------------");
        red();
        printf("\nCart is empty\n");
        reset();
        getch();
        return;
    }
    bill();
    int b,c,upi,cvv,dd,mm,yyyy,f,otp,hno;
    char n[100],use[100],lmark[100],area[100],phno[100];
    // printf("\n ---------  ADDRESS ---------\n");
    // printf("\n Name : ");
    // yellow();
    // scanf("%s",&use[30]);
    // reset();

    // printf("\n\n House No. : # ");
    // yellow();
    // scanf("%d",&hno);
    // reset();

    // printf("\n\nNear Landmark : ");
    // yellow();
    // scanf("%s",&lmark[50]);
    // reset();

    // printf("\n\nArea : ");
    // yellow();
    // scanf("%s",&area[60]);
    // reset();

    // printf("\n\n Phone No. : ");
    // yellow();
    // scanf("%s",&phno[10]);
    // reset();
    //printf("\n Your Total:%d\n",total);
    do
    {
      printf("\n========  payment  =======\n\n");
      cyan();
      printf("[1] => UPI\n");
      printf("[2] => Credit card\n");
      printf("[3] => Debit card\n");
      printf("[4] => Cash\n");
      reset();
      printf("\n=======================\n");
      
      printf("Select Mode Of Payment:");
      yellow();
      scanf("%d",&b);
      reset();
      if(b>4)
      {
         red();
         printf("Enter valid payment method\n");
         reset();
      }
    }
    while (b>4);

   switch(b)
   {
      case 1: 
      do
      {
        printf("\n======== UPI =======\n\n");
        cyan();
        printf("[1] => Phone Pe\n");
        printf("[2] => Google Pay\n");
        printf("[3] => Paytm\n");
        printf("\n");
        reset();
        printf("Select your Convinient One:");
        yellow();
        scanf("%d",&c);
        reset();
        if(c>3)
        {
            red();
            printf("\n Invalid \n");
            reset();
        }
      }while(c>3);
      printf("\n");
      printf("\nRedirecting to %.30s",str1[c-1]);
      for(int i=0;i<=5;i++)
      {  
         yellow();
         msleep(150);
         printf(".");
      }
      reset();
      printf("\n");
      printf("Please wait");
      printf("\nLoading");
      for(int i=0;i<=5;i++){
         yellow();
         msleep(150);
         printf(".");
      }           
      reset();
      printf("\nEnter your UPI PIN : ");
      int iq = 1;
      char ab[6],cd = " ";
      while(iq < 7)
      {
          ab[iq] = getch();
          cd = ab[iq];  
          iq++;
          yellow();
          printf("*");
          reset();
      }

      printf("\nPaying Securely");
      for(int i=0;i<=5;i++)
      {
         yellow();
         msleep(150);
         printf(".");
      }
      reset();
      printf("\n");
      
      break;

      case 2:
      case 3:
       printf("\n========  %.30s  =======\n\n",str2[b-2]);
       printf("Enter the Card Number :");
       yellow();
       scanf("%d",&f);
       reset();

       printf("\nName:");
       yellow();
       scanf("%s",n);
       reset();

       printf("\nExpiry Date :");
       yellow();
       scanf("%d/%d/%d",&dd,&mm,&yyyy);
       reset();

       printf("\nCVV Number :");
       int z = 1;
       char bd[6],cc = " ";
       while(z < 4)
        {
            bd[z] = getch();
            cc = bd[z];  
            z++;
            yellow();
            printf("*");
            reset();
        }
        printf("\n");
        printf("\nEnter OTP :");
        int q = 1;
        //char ab[6],cd = " ";
        while(q < 7)
        {
            ab[q] = getch();
            cd = ab[q];  
            q++;
            yellow();
            printf("*");
            reset();
        }
        break;

        case 4 : 
        green();
        printf("Order Succesful\n");
        reset();
        break;
    }
    payflag = 1;
    green();
    printf("\n\n Payment successfull\n");
    reset();

    printf("\n - - - - - - - - - - -\n");
    green();
    printf("\n Order Placed Successfully\n\n");
    reset();
    getch();
    
    endflag = 1;
  
}

void admin()
{
    int loginflag = 0,or;
    cartflag = 1;
    if(loginflag == 0)
    {
        login();
    }
    int ch;
    while(1)
    {
        do
        {
            system("cls");
            printf("\n------ ADMIN SECTION ------\n");
            printf("\n[1] -> Add Items\n");
            printf("\n[2] -> Remove Items\n");
            printf("\n[3] -> Alter price of an Item\n");
            printf("\n[4] -> View orders\n");
            printf("\n[0] -> BACK\n");
            printf("\n Enter : ");
            yellow();
            scanf("%d",&ch);
            reset();
            if(ch>4)
            {
                red();
                printf("\nInvalid\n");
                reset();
            }
        }while(ch>4);
        switch(ch)
        {

            case 1 : 
                    loginflag = 1;
                    insertrear(); 
                    break;
            case 2 : 
                    loginflag = 1;
                    deleterear();
                    break;
            case 3 : 
                    loginflag = 1;
                    alterprice();
                    break;
            case 4 : 
                    if(array[0] == NULL || payflag == 0)
                    {
                        red();
                        printf("\n No Orders\n");
                        reset();
                        getch();
                        break;
                    }
                    adminorderflag = 1;
                    payflag = 0;
                    printf("\nName : ");
                    green();
                    puts(username);
                    reset();
                    printf("\n\nPhNo : ");
                    green();
                    puts(phno);
                    reset();
                    cart();
                    do
                    {
                        printf("\n [1] -> Order being Prepared \n");
                        printf("\n [2] -> Order Completed \n");
                        printf("\n Enter : ");
                        yellow();
                        scanf("%d",&or);
                        reset();
                        if(or>2)
                        {
                            red();
                            printf("\nInvalid\n");
                            reset();
                        }
                        if(or == 2)
                        {
                            for(int i=0;i<=30;i++)
                            {
                                array[i] = NULL;
                            }
                            a_num = 0;
                        }
                    }while(or>2);
                    payflag = 1;
                    break;
            case 0 :
                    return;

        }
    }
}

void login()
{
    system("cls");
    int n,m,c=1;
    char a[15], b[15], d =' ';
    do
    {
    printf("\n ++++++++ Admin page +++++++\n");
    printf("\nUSER NAME: ");

    yellow();

    scanf("%s",&a);

    reset();

    printf("\nPASSWORD:  ");

    yellow();
    int i = 0;
    while(i<5)
    {
        b[i]=getch();
        d = b[i];
        // if(c==0)
        // break;
        // else
        printf("*");
        i++;
    }
    b[i]='\0';
    i=0;
    getch();


    reset();

    
    if(strcmp(a,"admin") == 0 && strcmp(b,"login") == 0)
   {
        green();
        printf("\n\nLOGIN SUCCESSFUL\n");

        time_t t;  
        time(&t);
        cyan();
        printf("\n%s\n", ctime(&t));

        green();
        printf("\n!! WELCOME L - M - A - N - H !!\n",b);
        reset();
        getch();

        return;

   }

   else

    {
        red();
        printf("\nINCORRECT PASSWORD\n");
        printf("LOGIN UNSUCCESFUL.....PLEASE TRY AGAIN.....\n");
        reset();
        c++;
        getch();
    }
    }
   while(c!=4);
   red();
   printf("\nYou have Entered wrong password many times........\n");
   printf("Please try after some time\n");
   reset();
   getch();
   main();
}


void insertrear()
{
    NODE cur;
    cur = first;
    char it_name[30];
    float it_price;
    
    system("cls");
    printf("\n------ ADD ITEMS ------\n");
    printf("\n\n Item Name : ");
    yellow();
    scanf("%s",it_name);
    reset();

    printf("\n\n Item Price : ");
    yellow();
    scanf("%f",&it_price);
    reset();
    
    MALLOC(tfood,sizeof(struct food),NODE);
    
    tfood->num = list_count + 1;
    strcpy(tfood->name,it_name);
    tfood->price = it_price;
    tfood->link = NULL;
    
    while(cur->link != NULL)
    {    
        cur = cur->link;
    }
    cur->link = tfood;
    list_count++;
    deleteflag = 1;
    food_order();
    green();
    printf("\nItem Added to List Successfully\n");
    reset();
    getch();
}

void deleterear()
{
    deleteflag = 1;
    food_order();
    printf("\nEnter item Code : ");
    int del_num;
    char item[30];
    yellow();
    scanf("%d",&del_num);
    reset();
    if(del_num>list_count)
    {
        red();
        printf("\nInvalid\n");
        reset();
        getch();
        return;
    }
    int td = del_num;
    NODE del = first;
    NODE pre = NULL;
    NODE nocha;
    NODE prnt;
    while(del != NULL)
    {
        if(del_num == del->num)
        {
            prnt = del;
            pre->link = del->link;
            nocha = pre->link;
        }
        pre = del;
        del = del->link;
    } 

    printf("\nItem : ");
    green();
    printf("%s\n",prnt->name);
    reset();
    free(del);
    list_count--;
    deleteflag = 1;
    getch();
    system("cls");
    food_order();
    
    green();
    printf("\n Item deleted successfully\n");
    reset();
    while(nocha != NULL)
    {
        nocha->num = td++;
        nocha = nocha->link;
    }
    getch();
}

void alterprice()
{
    altpriceflag = 1;
    int price_code, foundcode = 0,newprice;
    food_order();
    printf("\nEnter Item Num: ");
    yellow();
    scanf("%d",&price_code);
    reset();
    NODE alter = first;
    while(alter != NULL)
    {
        if(price_code == alter->num)
        {
            foundcode = 1;
            green();
            printf("\nItem found\n");
            reset();
            printf("\nItem : ");
            green();
            printf("%s",alter->name);
            reset();
            printf("\n");
            printf("\nPrice : ");
            green();
            printf("%.2f",alter->price);
            reset();
            printf("\n");
            printf("\nEnter the New Price :");
            yellow();
            scanf("%d",&newprice);
            reset();
            alter->price = newprice;
        }
        alter = alter->link;
    }
    if(foundcode == 0)
    {
        red();
        printf("\nItem not Found\n");
        reset();
        getch();
        return;
    }

    system("cls");
    altpriceflag = 1;
    food_order();
    green();
    printf("\nPrice Altered Successfully\n");
    reset();
    getch();
}


void bill()
{
    billflag = 1;
    cart();
    green();
    printf("\nORDER SUCCESSFULL\n");
    reset();
    getch();

}

void edit()
{
    int edit_num;
    while(1)
    {
        do
        {
            system("cls");
            printf("\n[1] -> Delete an item\n");
            printf("\n[2] -> Edit quantity\n");
            printf("\n[0] -> BACK\n");
            printf("\nEnter : ");
            yellow();
            scanf("%d",&edit_num);
            reset();
            if(edit_num>2)
            {
                red();
                printf("\nInvalid\n");
                reset();
                getch();
            }
        }while(edit_num>2);
        switch(edit_num)
        {
            case 1 : 
                deletecart();
                break;
            
            case 2 :
                quantitycart();
                break;
            case 0 : 
                system("cls");
                return;

        }
    }
}

void deletecart()
{
    system("cls");
    editflag = 1;
    cart();
    int item_code, foundflag = 0;

    printf("\nEnter the item code : ");
    yellow();
    scanf("%d",&item_code);
    reset();
    for(int i=0; i<=cart_count; i++)
    {
        if(item_code == array[i])
        {
            foundflag = 1;
            green();
            printf("Item Found");
            getch();
            reset();
            for(int j=i ;j<=cart_count; j++)
            {
                array[j] = array[j+1];
            }
        }
    }
    if(foundflag == 0)
    {
        red();
        printf("\nItem code not found\n");
        reset();
        getch();
        return;
    }

    system("cls");
    editflag = 1;
    cart();
    if(array[0] == NULL)
    {
        return;
    }
    green();
    printf("\nItem deleted successfully\n");            
    reset();
    getch();
}

void quantitycart()
{
    system("cls");
    editflag = 1;
    NODE tem,tem1;
    tem = first;
    cart();
    int item_c,new_quant,cflag = 0;

    printf("\nEnter the item code : ");
    yellow();
    scanf("%d",&item_c);
    reset();
    for(int i=0; i<=cart_count; i++)
    {
        if(item_c == array[i])
        {
            cflag = 1;
            green();
            printf("\nItem Code found\n");
            reset();
            while(tem != NULL)
            {
                if(item_c == tem->num)
                {
                    tem1 = tem;
                    printf("\nItem : ");
                    green();
                    printf("%s",tem->name);
                    reset();
                    printf("\n");
                    printf("\nQuantity : ");
                    green();
                    printf("%d",tem->quantity);
                    reset();
                    printf("\n");
                }
                tem = tem->link;
            }
            printf("\nEnter the new quantity :");
            yellow();
            scanf("%d",&new_quant);
            reset();
        }
    }
    if(cflag == 0)
    {
        red();
        printf("\nItem code not found\n");  
        reset();
        getch();
        return;
    }
    // while(tem != NULL)
    // {
    //     if(item_c == tem->num)
    //     {
    //         tem->quantity = new_quant;
    //     }
    //     tem = tem->link;
    // }
    tem1->quantity = new_quant;
    

    system("cls");
    editflag = 1;
    cart();
    green();
    printf("\nQuantity Updated successfully\n");
    reset();
    getch();
}

void spacing(char name[50], float price,int space)
{
    int x=0,intpart,i;
    while(name[x]!='\0')
    {
        space--;
        x++;
    }
    intpart = (int)price;
    while(intpart!=0)
    {
        space--;
        intpart /= 10;
    }
    for(i=1;i<=space;i++)
    {
        printf(" ");
    }
}

