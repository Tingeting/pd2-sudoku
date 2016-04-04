/*Sudoku.cpp*/
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;


void Sudoku::giveQuestion(){

	int question[81] = {

        8,0,0,4,0,6,0,0,7,
        0,0,0,0,0,0,4,0,0,
        0,1,0,0,0,0,6,5,0,
        5,0,9,0,3,0,7,8,0,
        0,0,0,0,7,0,0,0,0,
        0,4,8,0,2,0,1,0,3,
        0,5,2,0,0,0,0,9,0,
        0,0,1,0,0,0,0,0,0,
        3,0,0,9,0,2,0,0,5,
	};
	
	int i=0;
	
	while(i<=80){
		
		printf("%d",question[i]);
		(i+1)%9==0?printf("\n"):printf(" ");
		i++;
	}
}


void Sudoku::readIn(){
	
	int i=0;

	while(i<81){

		scanf("%d", &cube[i]);
		i++;
	}

}

/*
void sudoku::solve(){

	int i=0,j=0;
	
	int zero=0;

	for(i=0;i<81;i++){

			if(cube[i]==0) zero++;
	}

//	printf("%d",zero);

	int zeroSite[zero];

	for(i=0;i<81;i++){

		if(cube[i]==0){

			zeroSite[j]=i;
			j++;
		}
	}

/*		for(i=0;i<zero;i++){

			printf("%d\n", zeroSite[i]);
		}

	int cubeElement[zero][9];
	
	for(i=0;i<zero;i++){

		for(j=0;j<9;j++){

			cubeElement[i][j]=j+1;
		}
	}//OK

	i=0; //test
	j=0;

	for(i=0;i<zero;i++){

		for(j=0;j<9;j++){

			printf("%d",cubeElement[i][j]);
			(j+1)%9==0?printf("\n"):printf(" ");
		}
	} 

	int k,l;

	for(i=0;i<zero;i++){

		for(j=0;j<9;j++){

			for(k=0;k<9;k++){					

				if(cubeElement[i][j]==cube[(zeroSite[i]/9)*9+k]){
	
					cubeElement[i][j]=0;
				}
				if(cubeElement[i][j]==cube[zeroSite[i]%9+k*9]){
	
					cubeElement[i][j]=0;			
				}
				if(cubeElement[i][j]==cube[((zeroSite[i])/27)*27+((zeroSite[i]%9)/3)*3+k%3+k/3*9]){
	
					cubeElement[i][j]=0;			
				}			
			}
		}	
	}
	int Zero=82;
	bool element[9][9][9];

	while(Zero!=zero&&zero){

		Zero=zero;

		for(i=0;i<9;i++){

			for(j=0;j<9;j++){

				
			}	
		}
	}
	
	int whereElement[zero];

	for(i=0;i<zero;i++){

		whereElement[i]=0;
	}

	for(i=0;i<zero;i++){

		for(j=whereElement[i];j<9;j++){

			if(cubeElement[i][j]!=0){
					
				cube[zeroSite[i]]=cubeElement[i][j];
				whereElement[i]=j;
				break;
			}
		}

		for(k=0;k<9;k++){		

			if(cube[zeroSite[i]]==cube[(zeroSite[i]/9)*9+k]){
	
				whereElement[i]++;
				i--;
				break;
			}
			if(cube[zeroSite[i]]==cube[zeroSite[i]%9+k*9]){
		
				whereElement[i]++;
				i--;
				break;
			}
			if(cube[zeroSite[i]]==cube[((zeroSite[i])/27)*27+((zeroSite[i]%9)/3)*3+k%3+k/3*9]){
		
				whereElement[i]++;
				i--;
				break;
			}
		}		
	}




}
*/


/*	for(i=0;i<zero;i++){

		for(j=0;j<9;j++){

			printf("%d", cubeElement[i][j]);
			(j+1)%9==0?printf("\n"):printf(" ");
		}
	}
*/



void Sudoku::changeNum(int a, int b){
	
	if(a<=0||b<=0||a>9||b>9){

		printf("ERROR");
		exit(1);
	}
	
	int i=0;
	
	while(i<=80){
	
		if(cube[i]==a)	cube[i]=b;
		else if(cube[i]==b)	cube[i]=a;	
		i++;
	}

}


void Sudoku::changeRow(int a, int b){

	if(a<0||b<0||a>2||b>2){

		printf("ERROR");
		exit(1);
	}

	int change;
	int i,j;

	for(i=0;i<27;i++){

			change=cube[27*a+i];
			cube[27*a+i]=cube[27*b+i];
			cube[27*b+i]=change;
	}

}


void Sudoku::changeCol(int a, int b){

	if(a<0||b<0||a>2||b>2){

		printf("ERROR");
		exit(1);
	}
	
	int change;
	int i,j;

	for(i=0;i<9;i++){

		for(j=0;j<3;j++){
		
			change=cube[9*i+3*a+j];
			cube[9*i+3*a+j]=cube[9*i+3*b+j];
			cube[9*i+3*b+j]=change;
		}
	}
}


void Sudoku::rotate(int n){
	
	if(n<0||n>100){

		printf("ERROR");
		exit(1);
	}
	
	n=n%4;

	int cubeNew[81];
	int i,j;
	
	i=0;
	
	if(n==0){
	
		for(i=0;i<81;i++){
		
			cubeNew[i]=cube[i];
		}
	}
	while(i<81){

		cubeNew[i]=0;
		i++;
	}

	if(n>0){
	
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((8-j-i)+9*(j-i))]=cube[9*i+j];
			}//rotate 90 degree
		}
	}
	while(i<81){

		cube[i]=cubeNew[i];
		i++;
	}
	if(n>1){
	
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((8-j-i)+9*(j-i))]=cube[9*i+j];
			}//rotate 90 degree
		}
	}
	while(i<81){

		cube[i]=cubeNew[i];
		i++;
	}
	if(n>2){
	
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((8-j-i)+9*(j-i))]=cube[9*i+j];
			}//rotate 90 degree
		}
	}
		/*else if(n==2){
		
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((8-j-i)+9*(8-j-i))]=cube[9*i+j];
			}//rotate 180 degree
		}
	}
	else if(n==3){
		
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((0-j+i)+9*(8-j-i))]=cube[9*i+j];
			}//rotate 270 degree
		}
	}
	else{
		
		for(i=0;i<81;i++){
		
			cubeNew[i]=cube[i];
		}
	}
*/	
	i=0;

	while(i<81){

		cube[i]=cubeNew[i];
		i++;
	}

}


void Sudoku::flip(int n){

	if(n<0||n>1){

		printf("ERROR");
		exit(1);
	}

	int i,j;
	int cubeNew[81];

	if(n==0){

		for(i=0;i<9;i++){
			
			for(j=0;j<9;j++){

				cubeNew[9*i+j+8-2*j]=cube[9*i+j];
			}//vertically
		}
	}
	else{

		for(i=0;i<9;i++){

			for(j=0;j<9;j++){

				cubeNew[9*i+j+9*(8-2*i)]=cube[9*i+j];
			}//horizontally
		}
	}
	
	i=0;

	while(i<81){

		cube[i]=cubeNew[i];
		i++;
	}
	
}


void Sudoku::transform(){

	srand(time(NULL));
	
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);

	printS();	
}


void Sudoku::printS(){
	
	int i=0;
	
	while(i<=80){
		
		printf("%d",cube[i]);
		(i+1)%9==0?printf("\n"):printf(" ");
		i++;
	}
	printf("\n");
}
/*
void Sudoku::solve(){

	int i,j;

	int cubeNew[9][9];

	for(i=0;i<9;i++){

		for(j=0;j<9;j++){

			cubeNew[i][j]=cube[9*i+j];
		}
	}

	//put value from cube into cubeNew
	//---------------------------------


	int k;

    bool num[9][9][9];

    for(i=0;i<9;i++){

        for(j=0;j<9;j++){

            if(cubeNew[i][j]){

                for(k=0;k<9;k++){

                    num[i][j][k]=false;
                }	
				num[i][j][cubeNew[i][j]-1]=true;
			}
            else{

                for(k=0;k<9;k++){

                    num[i][j][k]=true;
				}
			}
        }

    }

//-------------------------------------------------------------------
    int zero=82,Zero=81;
	int row,sum,ans,col;
	int m,n;

    while(Zero!=zero&&zero){

        Zero=zero;

        for(row=0;row<9;row++){

            for(col=0;col<9;col++){

				if(!cubeNew[row][col]){

					for(i=0;i<9;i++){

						if(cubeNew[i][col]) num[row][col][cubeNew[i][col]-1]=false;
					}
                    for(i=0;i<9;i++){//TEST ROW

                        if(cubeNew[row][i]){
					
							num[row][col][cubeNew[row][i]-1]=false;
						}
					}
                    for(i=0;i<3;i++){//TEST 3*3

                    	for(j=0;j<3;j++){

                            if(cubeNew[i-(row%3)+row][j+col-(col%3)]){ 

								num[row][col][cubeNew[i-(row%3)+row][j+col-(col%3)]-1]=false;
							}
						}
					}
				}
            }
        }
	//-----------------------------------------------------------
		
		for(i=0;i<9;i++){

			for(j=0;j<9;j++){

				sum=0;
			
				for(k=0;k<9;k++){

					if(num[i][j][k]){

						sum++;
						ans=k+1;
					}
				}
				if(sum==1) cubeNew[i][j]=ans;
			}
		}
	}
//-----------------------------------------------------------------------------


	
	for(i=0;i<9;i++){

		for(j=0;j<9;j++){

			cube[9*i+j]=cubeNew[i][j];
		}
	}

	printS();
	
}*/



/*
    int i,j;

    int cubeNew[9][9];

    for( i=0;i<9;i++){

        for( j=0;j<9;j++){

            cubeNew[i][j]=cube[9*i+j];
        }
    }

    int k;

    bool num[9][9][9];

    for(i=0;i<9;i++){

        for(j=0;j<9;j++){

            if(cubeNew[i][j]){

                for(k=0;k<9;k++){

                    num[i][j][k]=false;
                }  
				  num[i][j][cubeNew[i][j]-1]=true;   
            }
            else{

                for(k=0;k<9;k++){

                    num[i][j][k]=true;
                }
            }
        }

    }

//-------------------------------------------------------------------
    int zero,Zero=81;
    int row,sum,ans,col;
    int m,n;
	
	for(i=0;i<9;i++){

		for(j=0;j<9;j++){

			if(cubeNew[i][j]==0) zero++;
		}
	}

    while(Zero!=zero&&zero!=0){

        Zero=zero;

        for(row=0;row<9;row++){

            for(col=0;col<9;col++){

                if(cubeNew[row][col]==0){

                    for(i=0;i<9;i++){//TEST COL

                        if(cubeNew[i][col]){

                            num[row][col][cubeNew[i][col]-1]=false;
                        }
                    }
                    for(j=0;j<9;j++){//TEST ROW

                        if(cubeNew[row][j]){

                            num[row][col][cubeNew[row][j]-1]=false;
                        }
                    }
                    for(i=0;i<3;i++){//TEST 3*3

                        for(j=0;j<3;j++){

                            if(cubeNew[i-(row%3)+row][j+col-(col%3)]){

                                num[row][col][cubeNew[i-(row%3)+row][j+col-(col%3)]-1]=false;
                            }
                        }
                    }
                    //--------------------------------------------------                
                    sum=0;
                    for(k=0;k<9;k++){

                        if(num[row][col][k]){

                            sum++;
                            ans=k+1;
                        }
                    }

                    if(sum==1){

                        cubeNew[row][col]=ans;
                    }
                }
            }
        }

   		zero=0;

        for(i=0;i<9;i++){

            for(j=0;j<9;j++){

                if(!cubeNew[i][j]) zero++;
            }
        }
	
    for(i=0;i<9;i++){

        for(j=0;j<9;j++){

            if(cubeNew[i][j]){

                for(m=0;m<9;m++){

                    if(cubeNew[m][j]==cubeNew[i][j]&&i!=m){

                            printf("0\n");
                            return;
                    }
                }
                for(n=0;n<9;n++){

                        if(cubeNew[i][n]==cubeNew[i][j]&&j!=n){

                            printf("0\n");
                            return;
                        }
                    }
                for(m=0;m<3;m++){

                    for(n=0;n<3;n++){

                        if(cubeNew[i-(i%3)+m][j-(j%3)+n]==cubeNew[i][j]&&i!=(i-(i%3)+m)&&j!=j-(j%3)+n){

                            printf("0\n");
                            return;
                        }
                    }
                }
            }
        }
    }
}	

//-----------------------------------------------------------------------------
    if(zero){

        printf("2\n");
		return;
    }
    else{

        printf("1\n");
    }


    for(i=0;i<9;i++){

        for(j=0;j<9;j++){

            cube[9*i+j]=cubeNew[i][j];
        }
    }

    printS();
*/
 

int Sudoku::compare(int i,int j,int k){

	int l,m,n=(i/3)*3+3,o=(j/3)*3+3;
	
	for(l=0;l<9;l++){

		if(map[l][j]==k) return 0;
		if(map[i][l]==k) return 0;
	}
	
	for(l=(i/3)*3;l<n;l++){

		for(m=(j/3)*3;m<o;m++){

			if(map[l][m]==k) return 0;
		}
	}
	
	return 1;
}



void Sudoku::Solverec(){

	int i,j,k,zero=0;
	for(i=0;i<9;i++){
		
		for(j=0;j<9;j++){

			if(map[i][j]!=0) zero++;
		}
	}
	if(zero==81){

		ans++;
		for(i=0;i<9;i++){

			for(j=0;j<9;j++)
				mapans[i][j]=map[i][j];
		}
		if(ans>=2)	return;
	}
	for(i=0;i<9;i++){

		for(j=0;j<9;j++){

			if(map[i][j]==0){

				for(k=1;k<10;k++){

					if(compare(i,j,k)==1){

						map[i][j]=k;
						Solverec();
						map[i][j]=0;
						if(ans>=2)
							return;
					}
				}
				return;
			}
		}
	}
}



void Sudoku::solve(){
	
	int i,j,k;	

	for(i=0;i<9;i++){

		for(j=0;j<9;j++){

			map[i][j]=cube[9*i+j];
		}
	}
/*
for(i=0;i<9;i++){
for(j=0;j<9;j++){
	printf("%d",cube[9*i+j]);
	(j+1)%9==0?printf("\n"):printf(" ");
}}
*/
	int qq;
	int gg;
	int ff;

	for(i=0;i<81;i++){

		if(cube[i]!=0){

			qq=0;
			gg=0;
			ff=0;

			for(j=0;j<9;j++){

				if(cube[i]==cube[((i/9)*9+j)]){
				
					qq++;					
					
					if(qq>1){
						
						printf("0\n");
						exit(1);
					}
				}
				if(cube[i]==cube[(i%9+j*9)]){
				
					gg++;
	
					if(gg>1){
						
						printf("0\n");
						exit(1);
					}

				}
				if(cube[i]==cube[((i/27)*27+((i%9)/3)*3+j%3+j/3*9)]){
		
					ff++;

					if(ff>1){
						
						printf("0\n");
						exit(1);
					}
				}
			}
		}
		
	}



	int a,b;
	ans=0;
	Solverec();
	if(ans==0){

		printf("0\n");
	}
	
	if(ans==1){

		cout<<"1"<<endl;
		for(a=0;a<9;a++){

				for(b=0;b<9;b++){
				
					printf("%d",mapans[a][b]);
					(b+1)%9==0?cout<<"\n":cout<<" ";
				}
		}
	}
	if(ans==2)
			cout<<"2"<<endl;

}


/*	
	int count=0;
	int count2=0;
	int count3=0;

	for(i=0;i<81;i++){

			count=0;
			count2=0;
			count3=0;

			for(k=0;k<9;k++){					

				if(cube[i]==cube[(((i)/9)*9+k)]&&cube[i]!=0){
					
		
					if(count=2){
					printf("0\n");
					//exit(1);
					}


					count++;
					printf("%d",count);
					break;
				}
				if(map[i][j]==(map[i][j]%9+k*9)&&map[i][j]!=0){
	
					if(count2=2){	
					printf("0\n");
					exit(1);
					}
					count2++;
				}
				if(map[i][j]==(((map[i][j])/27)*27+((map[i][j]%9)/3)*3+k%3+k/3*9)&&map[i][j]!=0){
	
					if(count3=2){
					printf("0\n");
					exit(1);
					}
					count3++;
				}			
			}
	}
*/
