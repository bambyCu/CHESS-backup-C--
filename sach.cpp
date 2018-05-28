#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int y=0,x=0,bazuka=1,ysurad,xsurad,a;
char kralovna='Q',kral='K',strelec='S',kon='J',veza='I',bieli_pesiak='j',cierny_pesiak='o' ;
char pamet='v',priatel,nepriatel,cpamet;
bool stoper=true,tester1=true,tester2=true,kaput=true,enter=true,ciel_najdeny=true,poradie=true,koniec_hry=true;
/*bmapa je mapa ktora urcuje ktore policka maju bit cervene (okrem toho pomocou ktoreho sa pohybujes)
 a ktora sa taktiez vzdy vinuluje ked stlacis tlacidlo(for prikaz na konci pohyb_hrdinu())*/
  char zaciatok_hry[20][100]= {"toto je hra sachu    ",
 							  "1,pohybujes sa s tlacitkami :w,a,s,d (funguje iba bez caps lock)",
							  "2,ak sa chces pohnut s figurkou prejdi na nu s fialovym polickom,",
							  "stlac space a mozes sa premiestnit na akekolvek cerveno zafatbene miesto  na mape",
							  "3,ak si sa rozhodol ze chces urobyt nieco ine ale uz si stlacil space ,",
							  "tak sa mozes mozes vratit na figurku na ktorej si pred chvilou bol a stlacit space ",
							  "                           UZI SI HRU :D"};
 	char bmapa[8][8];
	 char mapa [9][9] = {  "IJSKQSJI",		//toto je hlavna mapa ktoru vidis
						  "oooooooo",
						  "        ",
						  "        ",
						  "        ",
						  "        ",
						  "jjjjjjjj",
						  "IJSQKSJI",};
	char cmapa [9][9] = { "bbbbbbbb",//toto je mapa ktora hovori o tom ktore figurky su biele a ktore cierne
						  "bbbbbbbb",
						  "nnnnnnnn",
						  "nnnnnnnn",
						  "nnnnnnnn",
						  "nnnnnnnn",
						  "cccccccc",
						  "cccccccc",};
	HANDLE SetColor(
	 HANDLE console,
	int fg = FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
 	int bg = 0)	

 {
 if(console == NULL)
 console = GetStdHandle(STD_OUTPUT_HANDLE);

 SetConsoleTextAttribute(console, fg | bg);

 return console;
 }
 
 
 
 void zaciatok ()
 {
 	for(int gfg=0;gfg<7;gfg++)
 	{
 		cout<<zaciatok_hry[gfg]<<endl;
	 }
	 getch();
 }
 void pohyb_hrdinu()
{
	
		switch(_getch())
		{
			case 'w':
				if (x!=0)
				{

					x--;//suradnica sa zmeni
				}
			break;
			case 's':
				if (x!=7)
				{
					x++;
				}
				
			break;
			case 'd':
				if (y!=7)
				{
					y++;
				}
			break;
			case'a':
				if (y!=0)
				{
					y--; 
				}
			break;
			case' ':
				if (enter&&cmapa [x][y]=='b'&&poradie||enter&&cmapa [x][y]=='c'&&!poradie)
				{
					enter=false;
					xsurad=x;
					ysurad=y; 
				}
				else if (!enter)
				{
					if (xsurad==x&&ysurad==y)
					{
						enter=true;
					}
					else if (bmapa [x][y]==-1)
					{
						if (mapa [x][y]==kral)
						{
							koniec_hry=false;
						}
						mapa [x][y]=mapa [xsurad][ysurad];
						cmapa [x][y]=cmapa [xsurad][ysurad];
						mapa [xsurad][ysurad]=' ';
						cmapa [xsurad][ysurad]=' ';
						enter=true;
						if (poradie)
						{
							poradie=false;
						}
						else if (!poradie)
						{
							poradie=true;
						}
					}
					
				}
			break;
		}
		if (enter)
		{
		
			for (int ola=0;ola<8;ola++)
				{
					for (int oa=0;oa<8;oa++)
					{
						bmapa [ola][oa]=1;
					}
		 		}
		}
}



void kreslic ()
{	
for (int xsurad=0;xsurad<8;xsurad++)
			{
				for (int ysurad=0;ysurad<8;ysurad++)
			{
				if (ysurad==y&&xsurad==x&&!enter)
				{
					{
						HANDLE console = SetColor(NULL, BACKGROUND_BLUE);
					}
				}
				else if (ysurad==y&&xsurad==x)
					{
						HANDLE console = SetColor(NULL, BACKGROUND_RED,BACKGROUND_BLUE);
					}
				else if (bmapa[xsurad][ysurad]==-1)
					{
						HANDLE console = SetColor(NULL, BACKGROUND_RED);
					}
				else if (cmapa[xsurad][ysurad]=='b')
				{
					if (bazuka==1)
						{
							HANDLE console = SetColor(NULL, BACKGROUND_GREEN,FOREGROUND_INTENSITY);
						}
					else if (bazuka==-1)
						{
							HANDLE console = SetColor(NULL, BACKGROUND_BLUE,FOREGROUND_INTENSITY);
						}
				}
				else if (bazuka==1)
					{
						HANDLE console = SetColor(NULL, BACKGROUND_GREEN);
					}
				else if (bazuka==-1)
					{
						HANDLE console = SetColor(NULL, BACKGROUND_RED,BACKGROUND_GREEN);
					}
				

				if(ysurad==7&&bazuka==-1 )
				{
					bazuka=1;
				} 
				else if (ysurad==7&&bazuka==1 )
				{
					bazuka=-1;
				}
				bazuka=bazuka*-1;
				cout <<mapa [xsurad][ysurad];
			}cout<<endl;
		
	}
	for (int ysurad=0;ysurad<8;ysurad++)
			{cout<<bmapa[ysurad]<<endl;}
}



void pozorovatel ()
{
	if (cmapa [x][y]=='c')
		{
			priatel='c';
			nepriatel='b';
		}
	else if (cmapa [x][y]=='b')
		{
			priatel='b';
			nepriatel='c';
		}
	if (poradie&&cmapa[x][y]=='b')
	{
	
	if (mapa[x][y]==cierny_pesiak )
	{
	if (cmapa [x+1][y]!=priatel)
		{
			bmapa [x][y]=-1;
			bmapa [x+1][y]=-1;
		}
	if (cmapa [x+1][y+1]==nepriatel)
	{
		bmapa [x+1][y+1]=-1;	
	}
	if (cmapa [x+1][y-1]==nepriatel)
	{
		bmapa [x+1][y-1]=-1;	
	}
	}
	else if (mapa[x][y]==bieli_pesiak )
	{
	if (cmapa [x+1][y]!=priatel)
		{
			bmapa [x][y]=-1;
			bmapa [x-1][y]=-1;
		}
	if (cmapa [x-1][y-1]==nepriatel)
	{
		bmapa [x-1][y-1]=-1;	
	}
	if (cmapa [x-1][y+1]==nepriatel)
	{
		bmapa [x-1][y+1]=-1;	
	}	
	}		
	else if (mapa[x][y]==kralovna )
	{
		ysurad=y;
		xsurad=x;
		//chyba je asi niekde tuna \/
		while (stoper)//tato strana sa pohybuje od figurky do Prava dole (hlada kde ma zacat zadavat -1 do mapi) 
		{
			if (cmapa [xsurad+1][ysurad+1]==priatel||cmapa [xsurad][ysurad]==nepriatel)//toto oznami ci si narazil na spoluhracovu alebo svoju figurku {zatvorka ccc}
			{
				tester1=false;
			}
			if (ysurad==7||xsurad==7||!tester1)//tuna njajde najnizsie miesto kde zacne cervena farba
			{
				bmapa [xsurad][ysurad]=-1;
				xsurad--;
				ysurad--; //skratka :je to tu aby sa nasledujuce if nespustilo ked sa nema
				/* tato cast mimo zatvorky while je preto lebo v zatvorke oznacenej {ccc}je cast cmapa [xsurad][ysurad]==nepriatel
				ktora musi byt aj v nasledujucej zatvorke, a kedze  je to ta ista podmienka "toto znamena ze ked sa spusti tato zatvorka spusti spusti sa aj nasledujuca 
				to znamena ze na tejto casti nebude ziadna farba*/
		
					while (stoper)//tu zacne pridelovat farbu smerom ku najvyzsiemu oznemu policku
				 {
							//toto je tu na to aby ked objavy tze ono samo to ma znak, tak aby sa nezastavilo
						if (cmapa [xsurad][ysurad]==priatel&&ysurad!=y&&xsurad!=x||cmapa [xsurad][ysurad]==nepriatel)
						{
							tester2=false;
						}
						if (tester2)
						{
							bmapa [xsurad][ysurad]=-1;
						}
						if (xsurad==0||ysurad==0||!tester2)//hlada nepriatela alebo koniec mapi
						{
							if (cmapa [xsurad-1][ysurad-1]==nepriatel)
							{
								cmapa [xsurad][ysurad]==-1;
							}
							stoper=false;
						}
						xsurad--;
						ysurad--;
					}
			}
			
			xsurad++;
			ysurad++;
		}
		tester1=true;
		tester2=true;
		stoper=true;
		
		
		
		ysurad=y;
		xsurad=x;
		
		while (stoper)//prava strana krivky
		{	
			if (cmapa [xsurad+1][ysurad-1]==priatel||cmapa [xsurad][ysurad]==nepriatel)
			{
				tester1=false;
			}
			if (ysurad==0||xsurad==7||!tester1)
			{
				if (cmapa [xsurad][ysurad]==nepriatel)
				{
				bmapa [xsurad][ysurad]=-1;
				ysurad++;
				xsurad--;
				}
				while (stoper)
				
				{
															//toto je tu na to aby ked objavy tze ono samo to ma znak, tak aby sa nezastavilo
					if (cmapa [xsurad-1][ysurad+1]==priatel&&ysurad+1!=y&&xsurad-1!=x||cmapa [xsurad][ysurad]==nepriatel)
					{
						tester2=false;
					}
					bmapa [xsurad][ysurad]=-1;
					if (xsurad==0||ysurad==7||!tester2)
					{
						stoper=false;
					}
					xsurad--;
					ysurad++;
				}
			}
			xsurad++;
			ysurad--;
		}
		tester1=true;
		tester2=true;
		stoper=true;
		kaput=true;
	}
	else if (mapa[x][y]==veza )
	{

		ysurad = y;
		
		while (stoper)//hladame najpravy bod
		{
			if (ysurad==7||cmapa[x][ysurad+1]==priatel&&cmapa[x][y]==priatel||cmapa[x][ysurad]==nepriatel)
			{
				while (stoper)
				{
					bmapa [x][ysurad]=-1;
						if (ysurad==0||cmapa[x][ysurad-1]==priatel&&ysurad-1!=y||cmapa[x][ysurad-1]==nepriatel&&ysurad-1!=y)
						{
							stoper=false;
						}
					ysurad--;
				}
			}
			ysurad++;
		}
		stoper=true;
		tester1=true;
		tester2=true;
		
		
		xsurad = x;
		
		while (stoper)//hladame najvyzsi bod
		{
			if (xsurad==7||cmapa[xsurad+1][y]==priatel||cmapa[xsurad][y]==nepriatel)
			{
				while (stoper)
				{
					bmapa [xsurad][y]=-1;
					if (xsurad==0||cmapa[xsurad-1][y]==priatel&&xsurad-1!=x||cmapa[xsurad-1][y]==nepriatel&&xsurad-1!=x)
					{
						stoper=false;
					}
					xsurad--;
				}
			}
			xsurad++;
		}
		stoper=true;
		tester1=true;
		tester2=true;
	}
	else if (mapa[x][y]==strelec )//potrebujem pomoc s timto a kralovnou
	{
		ysurad=y;
		xsurad=x;
		while (stoper)//tato strana sa pohybuje od figurky do Prava dole (hlada kde ma zacat zadavat -1 do mapi) 
		{
			if (cmapa [xsurad+1][ysurad+1]==priatel||cmapa [xsurad][ysurad]==nepriatel)//toto oznami ci si narazil na spoluhracovu alebo svoju figurku {zatvorka ccc}
			{
				tester1=false;
			}
			if (ysurad==7||xsurad==7||!tester1)//tuna njajde najnizsie miesto kde zacne cervena farba
			{
				bmapa [xsurad][ysurad]=-1;
				xsurad--;
				ysurad--; //skratka :je to tu aby sa nasledujuce if nespustilo ked sa nema
				/* tato cast mimo zatvorky while je preto lebo v zatvorke oznacenej {ccc}je cast cmapa [xsurad][ysurad]==nepriatel
				ktora musi byt aj v nasledujucej zatvorke, a kedze  je to ta ista podmienka "toto znamena ze ked sa spusti tato zatvorka spusti spusti sa aj nasledujuca 
				to znamena ze na tejto casti nebude ziadna farba*/
		
					while (stoper)//tu zacne pridelovat farbu smerom ku najvyzsiemu oznemu policku
				 {
							//toto je tu na to aby ked objavy tze ono samo to ma znak, tak aby sa nezastavilo
						if (cmapa [xsurad][ysurad]==priatel&&ysurad!=y&&xsurad!=x||cmapa [xsurad][ysurad]==nepriatel)
						{
							tester2=false;
						}
						if (tester2)
						{
							bmapa [xsurad][ysurad]=-1;
						}
						if (xsurad==0||ysurad==0||!tester2)//hlada nepriatela alebo koniec mapi
						{
							if (cmapa [xsurad][ysurad]==nepriatel)
							{
								bmapa [xsurad][ysurad]=-1;
							}
							stoper=false;
						}
						xsurad--;
						ysurad--;
					}
			}
			
			xsurad++;
			ysurad++;
		}
		tester1=true;
		tester2=true;
		stoper=true;
		
		
																						//krivka z ¼D 		
		ysurad=y;
		xsurad=x;
		
		while (stoper)
		{	
			if (cmapa [xsurad+1][ysurad-1]==priatel||cmapa [xsurad][ysurad]==nepriatel)
			{
				tester1=false;
			}
			if (ysurad==0||xsurad==7||!tester1)
			{
				if (cmapa [xsurad][ysurad]==nepriatel)
				{
				bmapa [xsurad][ysurad]=-1;
				ysurad++;
				xsurad--;
				}
				while (stoper)
				
				{
															//toto je tu na to aby ked objavy tze ono samo to ma znak, tak aby sa nezastavilo
					if (cmapa [xsurad-1][ysurad+1]==priatel&&ysurad+1!=y&&xsurad-1!=x||cmapa [xsurad][ysurad]==nepriatel)
					{
						tester2=false;
					}
					bmapa [xsurad][ysurad]=-1;
					if (xsurad==0||ysurad==7||!tester2)
					{
						stoper=false;
					}
					xsurad--;
					ysurad++;
				}
			}
			xsurad++;
			ysurad--;
		}
		tester1=true;
		tester2=true;
		stoper=true;
		kaput=true;
	}
	else if (mapa[x][y]==kon )
	{
		if (x>=3)
		{
			if (cmapa[x-3][y-1]!=priatel )
			{
				if (y>=1)
				{
					bmapa [x-3][y-1]=-1;
				}
			}
			if (cmapa[x-3][y+1]!=priatel )
			{
				if (y<=6)
				{
					bmapa [x-3][y+1]=-1;
				}
			}
			
		}
		if (x<=5)
		{
			if (cmapa[x+3][y-1]!=priatel )
			{
				if (y>=1)
				{
					bmapa [x+3][y-1]=-1;
				}
			}
			
			if (cmapa[x+3][y+1]!=priatel )
			{
				if (y<=6)
				{
					bmapa [x+3][y+1]=-1;
				}
			}
			
		
		
		}
		if (x>=1)
		{
			if (cmapa[x-1][y-3]!=priatel )
			{
				if (y>=3)
				{
					bmapa [x-1][y-3]=-1;
				}
			}
			if (cmapa[x-1][y+3]!=priatel )
			{
				if (y<=5)
				{
					bmapa [x-1][y+3]=-1;
				}
			}
			
		}
		if (x<=6)
		{
			if (cmapa[x+1][y-3]!=priatel )
			{
				if (y>=3)
				{
					bmapa [x+1][y-3]=-1;
				}
			}
			if (cmapa[x+1][y+3]!=priatel )
			{
				if (y<=5)
				{
					bmapa [x+1][y+3]=-1;
				}
			}
			
		}
	}
	else if (mapa[x][y]==kral)
	{
		for (xsurad=1;xsurad>=-1;xsurad--)
		{
			for (ysurad=1;ysurad>=-1;ysurad--)
			{
				if (cmapa[x+xsurad][y+ysurad]!=priatel)
				{
					bmapa[x+xsurad][y+ysurad]=-1;
				}
			}
		}
		
	}
	}
	else if (!poradie&&cmapa[x][y]=='c')
	if (mapa[x][y]==cierny_pesiak )
	{
	if (cmapa [x+1][y]!=priatel)
		{
			bmapa [x][y]=-1;
			bmapa [x+1][y]=-1;
		}
	if (cmapa [x-1][y-1]==nepriatel)
	{
		bmapa [x-1][y-1]=-1;	
	}
	if (cmapa [x-1][y+1]==nepriatel)
	{
		bmapa [x-1][y+1]=-1;	
	}
	}
	else if (mapa[x][y]==bieli_pesiak )
	{
	if (cmapa [x-1][y]!=priatel)
		{
			bmapa [x][y]=-1;
			bmapa [x-1][y]=-1;
		}
	if (cmapa [x-1][y-1]==nepriatel)
	{
		bmapa [x-1][y-1]=-1;	
	}
	if (cmapa [x-1][y+1]==nepriatel)
	{
		bmapa [x-1][y+1]=-1;	
	}	
	}
	else if (mapa[x][y]==kralovna )
	{
		ysurad=y;
		xsurad=x;
		//chyba je asi niekde tuna \/
		while (stoper)//tato strana sa pohybuje od figurky do Prava dole (hlada kde ma zacat zadavat -1 do mapi) 
		{
			if (cmapa [xsurad+1][ysurad+1]==priatel||cmapa [xsurad][ysurad]==nepriatel)//toto oznami ci si narazil na spoluhracovu alebo svoju figurku {zatvorka ccc}
			{
				tester1=false;
			}
			if (ysurad==7||xsurad==7||!tester1)//tuna njajde najnizsie miesto kde zacne cervena farba
			{
				bmapa [xsurad][ysurad]=-1;
				xsurad--;
				ysurad--; //skratka :je to tu aby sa nasledujuce if nespustilo ked sa nema
				/* tato cast mimo zatvorky while je preto lebo v zatvorke oznacenej {ccc}je cast cmapa [xsurad][ysurad]==nepriatel
				ktora musi byt aj v nasledujucej zatvorke, a kedze  je to ta ista podmienka "toto znamena ze ked sa spusti tato zatvorka spusti spusti sa aj nasledujuca 
				to znamena ze na tejto casti nebude ziadna farba*/
		
					while (stoper)//tu zacne pridelovat farbu smerom ku najvyzsiemu oznemu policku
				 {
							//toto je tu na to aby ked objavy tze ono samo to ma znak, tak aby sa nezastavilo
						if (cmapa [xsurad][ysurad]==priatel&&ysurad!=y&&xsurad!=x||cmapa [xsurad][ysurad]==nepriatel)
						{
							tester2=false;
						}
						if (tester2)
						{
							bmapa [xsurad][ysurad]=-1;
						}
						if (xsurad==0||ysurad==0||!tester2)//hlada nepriatela alebo koniec mapi
						{
							if (cmapa [xsurad-1][ysurad-1]==nepriatel)
							{
								cmapa [xsurad][ysurad]==-1;
							}
							stoper=false;
						}
						xsurad--;
						ysurad--;
					}
			}
			
			xsurad++;
			ysurad++;
		}
		tester1=true;
		tester2=true;
		stoper=true;
		
		
		
		ysurad=y;
		xsurad=x;
		
		while (stoper)//prava strana krivky
		{	
			if (cmapa [xsurad+1][ysurad-1]==priatel||cmapa [xsurad][ysurad]==nepriatel)
			{
				tester1=false;
			}
			if (ysurad==0||xsurad==7||!tester1)
			{
				if (cmapa [xsurad][ysurad]==nepriatel)
				{
				bmapa [xsurad][ysurad]=-1;
				ysurad++;
				xsurad--;
				}
				while (stoper)
				
				{
															//toto je tu na to aby ked objavy tze ono samo to ma znak, tak aby sa nezastavilo
					if (cmapa [xsurad-1][ysurad+1]==priatel&&ysurad+1!=y&&xsurad-1!=x||cmapa [xsurad][ysurad]==nepriatel)
					{
						tester2=false;
					}
					bmapa [xsurad][ysurad]=-1;
					if (xsurad==0||ysurad==7||!tester2)
					{
						stoper=false;
					}
					xsurad--;
					ysurad++;
				}
			}
			xsurad++;
			ysurad--;
		}
		tester1=true;
		tester2=true;
		stoper=true;
		kaput=true;
	}
	else if (mapa[x][y]==veza )
	{

		ysurad = y;
		
		while (stoper)//hladame najpravy bod
		{
			if (ysurad==7||cmapa[x][ysurad+1]==priatel&&cmapa[x][y]==priatel||cmapa[x][ysurad]==nepriatel)
			{
				while (stoper)
				{
					bmapa [x][ysurad]=-1;
						if (ysurad==0||cmapa[x][ysurad-1]==priatel&&ysurad-1!=y||cmapa[x][ysurad-1]==nepriatel&&ysurad-1!=y)
						{
							stoper=false;
						}
					ysurad--;
				}
			}
			ysurad++;
		}
		stoper=true;
		tester1=true;
		tester2=true;
		
		
		xsurad = x;
		
		while (stoper)//hladame najvyzsi bod
		{
			if (xsurad==7||cmapa[xsurad+1][y]==priatel||cmapa[xsurad][y]==nepriatel)
			{
				while (stoper)
				{
					bmapa [xsurad][y]=-1;
					if (xsurad==0||cmapa[xsurad-1][y]==priatel&&xsurad-1!=x||cmapa[xsurad-1][y]==nepriatel&&xsurad-1!=x)
					{
						stoper=false;
					}
					xsurad--;
				}
			}
			xsurad++;
		}
		stoper=true;
		tester1=true;
		tester2=true;
	}
	else if (mapa[x][y]==strelec )//potrebujem pomoc s timto a kralovnou
	{
		ysurad=y;
		xsurad=x;
		while (stoper)//tato strana sa pohybuje od figurky do Prava dole (hlada kde ma zacat zadavat -1 do mapi) 
		{
			if (cmapa [xsurad+1][ysurad+1]==priatel||cmapa [xsurad][ysurad]==nepriatel)//toto oznami ci si narazil na spoluhracovu alebo svoju figurku {zatvorka ccc}
			{
				tester1=false;
			}
			if (ysurad==7||xsurad==7||!tester1)//tuna njajde najnizsie miesto kde zacne cervena farba
			{
				bmapa [xsurad][ysurad]=-1;
				xsurad--;
				ysurad--; //skratka :je to tu aby sa nasledujuce if nespustilo ked sa nema
				/* tato cast mimo zatvorky while je preto lebo v zatvorke oznacenej {ccc}je cast cmapa [xsurad][ysurad]==nepriatel
				ktora musi byt aj v nasledujucej zatvorke, a kedze  je to ta ista podmienka "toto znamena ze ked sa spusti tato zatvorka spusti spusti sa aj nasledujuca 
				to znamena ze na tejto casti nebude ziadna farba*/
		
					while (stoper)//tu zacne pridelovat farbu smerom ku najvyzsiemu oznemu policku
				 {
							//toto je tu na to aby ked objavy tze ono samo to ma znak, tak aby sa nezastavilo
						if (cmapa [xsurad][ysurad]==priatel&&ysurad!=y&&xsurad!=x||cmapa [xsurad][ysurad]==nepriatel)
						{
							tester2=false;
						}
						if (tester2)
						{
							bmapa [xsurad][ysurad]=-1;
						}
						if (xsurad==0||ysurad==0||!tester2)//hlada nepriatela alebo koniec mapi
						{
							if (cmapa [xsurad][ysurad]==nepriatel)
							{
								bmapa [xsurad][ysurad]=-1;
							}
							stoper=false;
						}
						xsurad--;
						ysurad--;
					}
			}
			
			xsurad++;
			ysurad++;
		}
		tester1=true;
		tester2=true;
		stoper=true;
		
		
																						//krivka z ¼D 		
		ysurad=y;
		xsurad=x;
		
		while (stoper)
		{	
			if (cmapa [xsurad+1][ysurad-1]==priatel||cmapa [xsurad][ysurad]==nepriatel)
			{
				tester1=false;
			}
			if (ysurad==0||xsurad==7||!tester1)
			{
				if (cmapa [xsurad][ysurad]==nepriatel)
				{
				bmapa [xsurad][ysurad]=-1;
				ysurad++;
				xsurad--;
				}
				while (stoper)
				
				{
															//toto je tu na to aby ked objavy tze ono samo to ma znak, tak aby sa nezastavilo
					if (cmapa [xsurad-1][ysurad+1]==priatel&&ysurad+1!=y&&xsurad-1!=x||cmapa [xsurad][ysurad]==nepriatel)
					{
						tester2=false;
					}
					bmapa [xsurad][ysurad]=-1;
					if (xsurad==0||ysurad==7||!tester2)
					{
						stoper=false;
					}
					xsurad--;
					ysurad++;
				}
			}
			xsurad++;
			ysurad--;
		}
		tester1=true;
		tester2=true;
		stoper=true;
		kaput=true;
	}
	else if (mapa[x][y]==kon )
	{
		if (x>=3)
		{
			if (cmapa[x-3][y-1]!=priatel )
			{
				if (y>=1)
				{
					bmapa [x-3][y-1]=-1;
				}
			}
			if (cmapa[x-3][y+1]!=priatel )
			{
				if (y<=6)
				{
					bmapa [x-3][y+1]=-1;
				}
			}
			
		}
		if (x<=5)
		{
			if (cmapa[x+3][y-1]!=priatel )
			{
				if (y>=1)
				{
					bmapa [x+3][y-1]=-1;
				}
			}
			
			if (cmapa[x+3][y+1]!=priatel )
			{
				if (y<=6)
				{
					bmapa [x+3][y+1]=-1;
				}
			}
			
		
		
		}
		if (x>=1)
		{
			if (cmapa[x-1][y-3]!=priatel )
			{
				if (y>=3)
				{
					bmapa [x-1][y-3]=-1;
				}
			}
			if (cmapa[x-1][y+3]!=priatel )
			{
				if (y<=5)
				{
					bmapa [x-1][y+3]=-1;
				}
			}
			
		}
		if (x<=6)
		{
			if (cmapa[x+1][y-3]!=priatel )
			{
				if (y>=3)
				{
					bmapa [x+1][y-3]=-1;
				}
			}
			if (cmapa[x+1][y+3]!=priatel )
			{
				if (y<=5)
				{
					bmapa [x+1][y+3]=-1;
				}
			}
			
		}
	}
	else if (mapa[x][y]==kral)
	{
		for (xsurad=1;xsurad>=-1;xsurad--)
		{
			for (ysurad=1;ysurad>=-1;ysurad--)
			{
				if (cmapa[x+xsurad][y+ysurad]!=priatel)
				{
					bmapa[x+xsurad][y+ysurad]=-1;
				}
			}
		}
		
	}
	}

int main(int argc, char** argv) {
	zaciatok ();
	system("cls");
	while (koniec_hry)	
		{
	if (enter)
	{
		pozorovatel ();
	}
	 
	 kreslic ();
	 pohyb_hrdinu();
	
	
	system ("cls");
		}
	if (enter)
	{
		cout<<"bieli vyhral";
	}
	else if (!enter)
	{
		cout<<"cierny vyhral";
	}
	return 0;
}
