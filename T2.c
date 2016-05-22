#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	
	int m1,m2,c1[6],c2[5];
	int w;
	struct no *um;
	struct no *dois;
	struct no *tres;
	struct no *quatro;
	struct no *cinco;
	struct no *seis;

}t_no;

t_no *playhuman(t_no *no);
t_no *playpc(t_no *no);
int possiveljogarhuman(t_no *no);
int possiveljogarpc(t_no *no);
int valido(t_no *no);
int finishthegame(t_no *no);

t_no *criarNo(){
   
   t_no *n = (t_no *)malloc(sizeof(t_no));
   n->um = NULL;
   n->dois = NULL;
   n->tres = NULL;
   n->quatro = NULL;
   n->cinco = NULL;
   n->seis = NULL;

   return n;
}

void imprimatab(t_no *no){
	printf("| %2d  |",no->m1);
	
	for(int i = 0; i <= 5; ++i){
 		printf(" %2d  |",no->c1[i]);
 	}

 	printf("   \n      |");

 	for(int i = 0; i <= 5; ++i){
 		printf(" %2d  |",no->c2[i]);
 	}

 	printf(" %2d  |",no->m2);
 	printf("\n");
}

int valido(t_no *no){
	int all=0;
	for (int i=0; i<=5 ; ++i){
		all+=no->c1[i];
		all+=no->c2[i];
	}
	if (all + no->m1 + no->m2 == 48){
		return 1;
	}else{
		return 0;
	}

}

int possiveljogarhuman(t_no *no){
	for (int i = 0; i < 6; ++i){
		if (no->c2[i]!=0){
			return 1;
		}
	}

	return 0;
}

int possiveljogarpc(t_no *no){
	for (int i = 0; i < 6; ++i){
		if (no->c1[i]!=0){
			return 1;
		}
	}

	return 0;
}

int finishthegame(t_no *no){

		//system("clear");
		if(!possiveljogarhuman(no)){
			no->m2++;
			no->m1 = 48 - no->m2;
			for(int i = 0; i < 6; ++i){
				no->c1[i]=0;
			}
		}else if (!possiveljogarpc(no)){
			no->m1++;
			no->m2=48 - no->m1;
			for(int i = 0; i < 6; ++i){
				no->c2[i]=0;
			}
		}
		imprimatab(no);
		printf("the game has done.\n");
		if (no->m1 > no->m2){
			no->w=1;
			printf("PC had won.\n");
		}else if (no->m1 < no->m2){
			no->w=0;
			printf("YOU won!.\n");
		}else{
			no->w=-1;
			printf("DRAW.\n");
		}
		return no->w;
}

t_no *playpc(t_no *no){

	//system("clear");
	if (!valido(no)){
		printf("TEM ERRO\n");
	}
	imprimatab(no);
	int move=46582;
	printf("PC playing..\n");
	do{
		if (move!=46582){
			if ((move>6||move<1||no->c1[move-1]==0) ){
				printf("option is invalid .. try again!\n");
			}
		}
	  scanf("%d",&move);
	}while(move>6||move<1||no->c1[move-1]==0); 
	int aux,i,f,z,v = move-1;
	int j=no->c1[v];
	no->c1[v]=0;
	z = j;
	for (i=v-1, f=0;  (i>=0 && f<j) ; --i,++f){
		if (f==j-1 && no->c1[i]==0 && no->c2[i]>0){
			no->m1 += (no->c2[i]+1);
			no->c2[i]=0;
		}else{
			no->c1[i]++;
		}
		--z;
	}
	if (z==1){
		no->m1++;
		--z;
		if(possiveljogarhuman(no) && possiveljogarpc(no)){
			playpc(no);
		}
	}else if(z>0){
			no->m1++;
			--z;
			aux=z;
			for (i=0; i<aux && i<=5 ; ++i){
				no->c2[i]++;
				--z;
			}
	}if (z>0){
		aux=z;
		for (i=5,f=0; i>(5-aux) && i>=0  ;--i,f++){
			if (f==aux-1 && no->c1[i]==0 && no->c2[i]>0){
				no->m1 += (no->c2[i]+1);
				no->c2[i]=0;
			}else{
				no->c1[i]++;
			}
			--z;
		}
	}if (z==1){
		no->m1++;
		--z;
		if(possiveljogarhuman(no) && possiveljogarpc(no)){
			playpc(no);
		}
	}else if(z>0){
			no->m1++;
			--z;
			aux=z;
			for (i=0; i<aux && i<=5 ; ++i){
				no->c2[i]++;
				--z;
			}
	}
	if(possiveljogarhuman(no) && possiveljogarpc(no)){
		playhuman(no);
	}else{
		finishthegame(no);
	}

	return(no);
}

t_no *playhuman(t_no *no){
	
	//system("clear");
	if (!valido(no)){
		printf("TEM ERRO\n");
	}
	imprimatab(no);
	int move=46582;
	printf("Your turn..\n");
	do{
		if (move!=46582){
			if ((move>6||move<1||no->c2[move-1]==0) ){
				printf("option is invalid .. try again!\n");
			}
		}
		scanf("%d",&move);
	}while(move>6||move<1||no->c2[move-1]==0); 
	
	int i,aux,z,f,j=no->c2[move-1];
	z=j;
	no->c2[move-1]=0;
	for (i=move-1,f=0; i < j+move-1 && i<5 ; ++f,++i){
		if (f==j-1 && no->c2[i+1]==0 && no->c1[i+1]>0){
			no->m2 += (no->c1[i+1]+1);
			no->c1[i+1]=0;
		}else{
			no->c2[i+1]++;
		}
		--z;
	}	
	if (z==1){
		no->m2++;
		--z;
		if(possiveljogarhuman(no)&&possiveljogarpc(no)){
			playhuman(no);
		}
	}else if(z>0){			
			no->m2++;
			--z;
			aux=z;
			for (i=0 ; i<aux && i<=5 ; ++i){
				no->c1[5-i]++;
				--z;
			}
	}if(z>0){
		aux=z; 
		for (i=0; i < aux && i<=5 ; ++i){
			if (i==aux-1 && no->c2[i]==0 && no->c1[i]>0){
				no->m2 += (no->c1[i]+1);
				no->c1[i]=0;
			}else{
				no->c2[i]++;
			}
			--z;
		}
	}if (z==1){
		no->m2++;
		--z;
		if(possiveljogarhuman(no)&&possiveljogarpc(no)){
			playhuman(no);
		}
	}else if(z>0){
			no->m2++;
			--z;
			aux=z;
			for (i=0 ; i<aux && i<=5 ; ++i){
				no->c1[5-i]++;
				--z;
			}
	}
	if(possiveljogarhuman(no) && possiveljogarpc(no)){
		playpc(no);
	}else{
		finishthegame(no);
	}
	return no;
}

void incializa(){
	int m;
	t_no *no = criarNo();
	no->m1 = 0;
	no->m2 = 0;
	for(int i = 0; i < 6; ++i){
		no->c1[i]=4;
		no->c2[i]=4;
	}
	system("clear");
	printf("To play first click 1\nTo play second click 2\n");
	scanf("%d",&m);
	switch (m){
		case 1 :
			playhuman(no);
			break;
		case 2:
			playpc(no);
			break;
	}
}

void main (){
	incializa();
}