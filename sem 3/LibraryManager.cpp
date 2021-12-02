#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Library{
	int Bno, Byearofpb;
	char Btitle[30], Bauthor[30], Bpublisher[30], subject[30]; 
}book[2700];

struct Date{
	int day, month, year;
};

struct CheckOut{
	char Name[30], Address[50], Phone[15];
	int IssuedBookNo; 
	struct Date Checkoutdate;
	struct Date Returndate;
}issuer[2700];

	void deleteBook(int i, int l)
	{
		for(int x=0;x<i;x++)
		{
			if (x>=l)
			{
				book[x].Bno=book[x+1].Bno;
				book[x].Byearofpb=book[x+1].Byearofpb;
				strcpy(book[x].Btitle, book[x+1].Btitle);
				strcpy(book[x].Bauthor, book[x+1].Bauthor);
				strcpy(book[x].Bpublisher, book[x+1].Bpublisher);
				strcpy(book[x].subject, book[x+1].subject);				
			}
		}
	}
	void addBook(int i)
	{
		printf("Enter book number: ");
		scanf("%d", &book[i].Bno);
		printf("Enter book title: ");
		scanf("%s", &book[i].Btitle);
		printf("Enter Author name: ");
		scanf("%s", &book[i].Bauthor);
		printf("Enter publisher name: ");
		scanf("%s", &book[i].Bpublisher);
		printf("Enter the year of publication: ");
		scanf("%d", &book[i].Byearofpb);
		printf("Subject: ");
		scanf("%s", &book[i].subject);
	}

int main(){
	
	char searchBauthor[30], searchsubject[30], searchBtitle[30];
	int choice, choice1, i=0, j=0,y=0, searchBno;
	printf("\t\t\t\t\t\tAnsprin Library Management\n");
	while(j==0)
	{
		printf("1) Add new books\n");
		printf("2) List of books in Library \n");
		printf("3) Search the library by book number, author, title, subject\n");
		printf("4) Remove outdated books (all books older than 15 years)\n");
		printf("5) Checkout books\n");
		printf("6) Return books\n");
		printf("7) Exit");
		printf("\n\nEnter your choice of action: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\t\t\t\t\t\tADD NEW BOOK\n");
				addBook(i);
				printf("--------------------------------------------------------------------------\n\n");
				i++;
				break;
			case 2:
				printf("\t\t\t\t\t\tLIST OF ISSUABLE BOOKS IN LIBRARY: \n");
				for(int k=0;k<i;k++)
				{
					printf("Book no: %d  ", book[k].Bno);
					printf("book title: %s  ", book[k].Btitle);
					printf("Author: %s  ",book[k].Bauthor);
					printf("Publisher: %s  ", book[k].Bpublisher);
					printf("year of publication: %d  ", book[k].Byearofpb);
					printf("Subject: %s\n\n", book[k].subject);
					printf("--------------------------------------------------------------------------\n\n");
				}
				if(i==0)
				{
					printf("NO BOOKS ADDED\n\n\n");
					printf("--------------------------------------------------------------------------\n\n");
				}
				break;
			case 3:
				printf("\t\t\t\t\t\tSEARCH BOOK\n");
				printf("Search books by ?\n\n");
				printf("1) Book number\n");
				printf("2) Author\n");
				printf("3) Title\n");
				printf("4) Subject\n\n");
				printf("Enter choice: ");
				scanf("%d", &choice1 );
				switch(choice1){
					case 1: 
						printf("Enter book number of the book you are searching for: ");
						scanf("%d", &searchBno);
						for(int l=0;l<i;l++)
						{
							if(searchBno==book[l].Bno)
							{
								printf("Book no: %d  ", book[l].Bno);
								printf("book title: %s  ", book[l].Btitle);
								printf("Author: %s  ",book[l].Bauthor);
								printf("Publisher: %s  ", book[l].Bpublisher);
								printf("year of publication: %d  ", book[l].Byearofpb);
								printf("Subject: %s\n\n", book[l].subject);	
								printf("--------------------------------------------------------------------------\n\n");
							}
						}
						break;
					case 2:
						printf("Enter Author of the book you are searching for: ");
						scanf("%s",searchBauthor);
						for(int l=0;l<i;l++)
						{
							if(strcmp(searchBauthor, book[l].Bauthor)==0)
							{
								printf("Book no: %d  ", book[l].Bno);
								printf("book title: %s  ", book[l].Btitle);
								printf("Author: %s  ",book[l].Bauthor);
								printf("Publisher: %s  ", book[l].Bpublisher);
								printf("year of publication: %d  ", book[l].Byearofpb);
								printf("Subject: %s\n\n", book[l].subject);		
								printf("--------------------------------------------------------------------------\n\n");
							}
						}
						break;
					case 3:
						printf("Enter book title of the book you are looking for: ");
						scanf("%s", searchBtitle);
						for(int l=0;l<i;l++)
						{
							if(strcmp(searchBtitle, book[l].Btitle)==0)
							{
								printf("Book no: %d  ", book[l].Bno);
								printf("book title: %s  ", book[l].Btitle);
								printf("Author: %s  ",book[l].Bauthor);
								printf("Publisher: %s  ", book[l].Bpublisher);
								printf("year of publication: %d  ", book[l].Byearofpb);
								printf("Subject: %s\n\n", book[l].subject);		
								printf("--------------------------------------------------------------------------\n\n");
							}
						}
						break;
					case 4:
						printf("Enter subject of the book you are looking for: ");
						scanf("%s", searchsubject);
						for(int l=0;l<i;l++)
						{
							if(strcmp(searchsubject, book[l].subject)==0)
							{
								printf("Book no: %d  ", book[l].Bno);
								printf("book title: %s  ", book[l].Btitle);
								printf("Author: %s  ",book[l].Bauthor);
								printf("Publisher: %s  ", book[l].Bpublisher);
								printf("year of publication: %d  ", book[l].Byearofpb);
								printf("Subject: %s\n\n", book[l].subject);		
								printf("--------------------------------------------------------------------------\n\n");
							}
						}
						break;				
				}
				break;
			case 4:
				for (int l=0;l<i;l++)
				{
					if(book[l].Byearofpb<2005)
					{
						deleteBook(i,l);
						i--;
						printf("All books published before 2005 have been removed from the library.\n(NOTE: press option 2 to see list of books in library.)\n");
						printf("--------------------------------------------------------------------------\n\n");
					}
				}
				break;
			case 5:
				printf("\t\t\t\t\t\tISSUE BOOK\n");
				printf("Enter name of issuer: ");
				scanf("%s", issuer[y].Name);
				printf("Enter address: ");
				scanf("%s", issuer[y].Address);
				printf("Enter phone no: ");
				scanf("%s", issuer[y].Phone);
				printf("Enter book number of the book to be issued: ");
				scanf("%d", &issuer[y].IssuedBookNo);
				for(int l=0;l<i;l++)
				{
					if(issuer[y].IssuedBookNo==book[l].Bno)
					{
						deleteBook(i,l);
						i--;
					}
				}
				printf("Enter checkout date: ");
				scanf("%d", &issuer[y].Checkoutdate);
				printf("The book has been issued successfully !!\n");
				printf("(Note: The issued book has been removed from the list of books. Press option 2 to view list of issuable books.)\n");
				printf("--------------------------------------------------------------------------\n\n");
				y++;
				break;
			case 6:
				printf("\t\t\t\t\t\tRETURN BOOK\n");
				printf("Enter name of issuer: ");
				scanf("%s", issuer[y].Name);
				printf("Enter address: ");
				scanf("%s", issuer[y].Address);
				printf("Enter phone no: ");
				scanf("%s", issuer[y].Phone);
				printf("Enter details of the book to be returned: \n\n");
				addBook(i);
				i++;
				printf("Enter return date: ");
				scanf("%d", &issuer[y].Checkoutdate);
				printf("The book has been returned successfully !!\n");
				printf("(Note: The issued book has been returned and added back to the list of books. Press option 2 to view list of issuable books.)\n");
				printf("--------------------------------------------------------------------------\n\n");
				y++;
				
				break;
			case 7:
				exit(0);
				break;
			
		}

 }
	return 0;
}
