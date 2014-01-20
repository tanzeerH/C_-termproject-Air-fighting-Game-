/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"



/* 
	function iDraw() is called again and again by the system.
*/
int ellipse_x,ellipse_y,brec_x,brec_y,srec_x,srec_y,fire=0,fire_x,fire_y,occurance=0,enemy=0,erec11_x,erec12_x,erec11_y,erec12_y,bang=0,bg_y=512,bg_x=0,myplane=1,efire_x,efire_y,ch1;
int start=1,begin=0,level=0,point=4,score=0,ch2,enemy2=0,erec21_x,erec21_y,erec22_x,erec22_y,o=0,e2fire_x,e2fire_y,bang2_x,bang2_y,bang2_r,bang2,speed=0,ch=0,high,chance;
double bang_x,bang_y,bang_r=10;
FILE *fp;

void iDraw()
{
	//place your drawing codes here	
	
	iClear();
	if(start==1)
	{
	
		
		iShowBMP(0,0,"image1.bmp");
		iSetColor(0,0,255);
		iFilledRectangle(350,300,200,175);
		iSetColor(0,255,255);
		iText(900,20,"AIRCOMBAT");
		iText(400,400,"1.START GAME");
		iText(400,380,"2.SAVE GAME");
		iText(400,360,"3.LOAD GAME");
		iText(400,340,"4.EXIT GAME");
	}
	
	if(begin==1)
	{
		iShowBMP(180,100,"f16.bmp");
		iSetColor(0,0,255);
		iFilledRectangle(350,300,200,175);
		iSetColor(0,255,255);
		iText(400,450,"CHOOSE LEVEL");
		iText(400,400,"1.EASY");
		iText(400,380,"2.MIDIUM");
		iText(400,360,"3.HARD");
		iText(900,20,"AIRCOMBAT");
	}
	

	
	if(begin==2)
	{
		iShowBMP(bg_x,bg_y,"bg1.bmp");

		iText(900,20,"AIRCOMBAT");
		iSetColor(0,0,255);
		if(level==1)
			iText(880,480,"LEVEL: EASY");
		if(level==2)
			iText(880,480,"LEVEL: MEDIUM");
		if(level==2)
			iText(880,480,"LEVEL: HARD");
		if(myplane==1)
		{
			iFilledEllipse(ellipse_x,ellipse_y,5,30,1000);
			iSetColor(255,255,255);
			iFilledRectangle(srec_x,srec_y,4,4);
			iSetColor(255,0,0);
			iFilledRectangle(brec_x,brec_y,50,8);
		}
			
		if(fire==1)
		{
			
			iSetColor(0,255,0);
			iFilledCircle(fire_x,fire_y,2,1000);
		}
		if(enemy==1)
		{
			iSetColor(255,255,0);
			iFilledRectangle(erec11_x,erec11_y,8,40);
			iSetColor(0,255,255);
			iFilledRectangle(erec12_x,erec12_y,30,6);
			iSetColor(255,0,0);
			
			iFilledCircle(efire_x,efire_y,2,1000);
		}
		if(enemy==1 && fire==1)
		{
			if((fire_y>erec11_y && fire_y<erec11_y+2 && fire_x>=erec11_x-3 && fire_y<=erec11_x+12) || (fire_y>erec12_y && fire_y<erec12_y+2 && fire_x>=erec12_x-4 && fire_y<=erec12_x+36))
			{
				enemy=0;
				bang=1;
				score=score+1;
			}
		}
		if(enemy==1)
		{
			if((erec11_x>=ellipse_x-10 && erec11_x<=ellipse_x+10) && (erec11_y<=ellipse_y+20 && erec11_y>ellipse_y))
			{
				bang=1;
				enemy=0;
				myplane=0;
				point=point-1;

			}
			
			if(efire_y>ellipse_y-18 && efire_y<ellipse_y+18 && efire_x>ellipse_x-4 && efire_x<ellipse_x+4)
			{
				bang=1;
				myplane=0;
				point=point-1;
			}
		}
		if(enemy2==1 && fire==1)
		{
			if((fire_y>erec21_y && fire_y<erec21_y+2 && fire_x>=erec21_x-3 && fire_y<=erec21_x+12) || (fire_y>erec22_y && fire_y<erec22_y+2 && fire_x>=erec22_x-4 && fire_y<=erec22_x+36))
			{
				enemy2=0;
				bang2=1;
				score=score+1;
			}
		}	
		if(enemy2==1)
		{
			if((erec21_x>=ellipse_x-10 && erec21_x<=ellipse_x+10) && (erec21_y<=ellipse_y+20 && erec21_y>ellipse_y))
			{
				bang2=1;
				enemy2=0;
				point=point-1;
				myplane=0;
				

			}	
			if(e2fire_y>ellipse_y-18 && e2fire_y<ellipse_y+18 && e2fire_x>ellipse_x-4 && e2fire_x<ellipse_x+4)
			{
				bang2=1;
				point=point-1;
				myplane=0;
				
			}
		}
			if((o+occurance)>chance && score<high)
				begin=3;
			if(point<0)
				begin=3;
			if(begin==3)
					iText(500,250,"GAME OVER");
			if(score>=high)
				begin=4;
			if(begin==4)
				iText(500,250,"YOU WIN");
			printf("%d\n",point);	

		switch(score)
		{
		case 0:
			iText(900,450,"HIT: 0");
		case 1:
			iText(900,450,"HIT: 1");
				break;
		case 2:
			iText(900,450,"HIT: 2");
				break;
		case 3:
			iText(900,450,"HIT: 3");
				break;
		case 4:
			iText(900,450,"HIT: 4");
				break;
		case 5:
			iText(900,450,"HIT: 5");
				break;
		case 6:
			iText(900,450,"HIT: 6");
				break;
		case 7:
			iText(900,450,"HIT: 7");
				break;
		case 8:
			iText(900,450,"HIT: 8");
				break;
		}

		iText(900,65,"LIFE");
		
			iRectangle(900,50,60,10);
		if(point==3)
		{
			iSetColor(255,0,0);
			iFilledRectangle(900,50,20,10);
		}

		if(point==2)
		{
			iSetColor(255,0,0);
			iFilledRectangle(900,50,40,10);
		}	
		if(point==1)
		{
			iSetColor(255,0,0);
			iFilledRectangle(900,50,60,10);
		}	
		
		if(bang>0)
			{
				iSetColor(255,0,0);
				iFilledCircle(bang_x,bang_y,bang_r,1000);
			}
		if(bang2>0)
			{
				iSetColor(255,0,0);
				iFilledCircle(bang2_x,bang2_y,bang2_r,1000);
			}
		if(enemy2==1)
		{
			iSetColor(255,0,255);
			iFilledRectangle(erec21_x,erec21_y,8,40);
			iSetColor(0,255,255);
			iFilledRectangle(erec22_x,erec22_y,30,6);

			iSetColor(255,0,0);
			
			iFilledCircle(e2fire_x,e2fire_y,2,1000);
		}
		


	}
	if(begin==3)
	{
		iText(500,250,"GAME OVER");
	}
	if(begin==4)
	{
			iText(500,250,"YOU WIN");
	}

}	
		
	


	
	


/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
	if(key=='f' && fire==0)
	{
		fire=1;
		fire_x=ellipse_x;
		fire_y=ellipse_y+15;
		
	}
	if(key == 'g')
	{
		begin=1;
		start=0;
	}
	if(key == 'q')
		exit(0);
	
	if(key=='l' && start==1)
	{
		fp=fopen("myfile.txt","r");
		fscanf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&ellipse_x,&ellipse_y,&brec_x,&brec_y,&srec_x,&srec_y,&fire,&fire_x,&fire_y,&occurance,&enemy,&erec11_x,&erec12_x,&erec11_y,&erec12_y,&bang,&myplane,&efire_x,&efire_y,&ch1);
		fscanf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&point,&score,&ch2,&enemy2,&erec21_x,&erec21_y,&erec22_x,&erec22_y,&o,&e2fire_x,&e2fire_y,&bang2_x,&bang2_y,&bang2_r,&bang2);
		fscanf(fp,"%d %d %d %d",&speed,&ch,&high,&chance);
		fclose(fp);
		begin=1;
		start=0;
	}

	if(key =='e' && begin==1)
	{
		begin=2;
		level=1;
		ch=1;
		speed=4;
		high=8;
		chance=30;

	}
	if(key=='m' && begin==1)
	{
		begin=2;
		level=2;
		ch=2;
		speed=6;
		high=8;
		chance=40;
	}
	if(key=='h' && begin==1)
	{
		begin=2;
		ch=3;
		speed=7;
		level=3;
		high=8;
		chance=50;
	}

	if(key == 'a')
	{
		begin=0;
		start=1;
	}
	if(key=='s' && begin==2)
	{
	
		
		fp=fopen("myfile.txt","w");
		fprintf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ",ellipse_x,ellipse_y,brec_x,brec_y,srec_x,srec_y,fire,fire_x,fire_y,occurance,enemy,erec11_x,erec12_x,erec11_y,erec12_y,bang,myplane,efire_x,efire_y,ch1);
		fprintf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",point,score,ch2,enemy2,erec21_x,erec21_y,erec22_x,erec22_y,o,e2fire_x,e2fire_y,bang2_x,bang2_y,bang2_r,bang2);
		fprintf(fp,"%d %d %d %d",speed,ch,high,chance);
		fclose(fp);
	}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key==GLUT_KEY_UP)
	{
		ellipse_y=ellipse_y+speed;
		brec_y=brec_y+speed;
		srec_y=srec_y+speed;
	}
	if(key==GLUT_KEY_DOWN)
	{
		ellipse_y=ellipse_y-speed;
		brec_y=brec_y-speed;
		srec_y=srec_y-speed;
	}
	if(key==GLUT_KEY_RIGHT)
	{
		ellipse_x=ellipse_x+speed;
		brec_x=brec_x+speed;
		srec_x=srec_x+speed;
	}
	if(key==GLUT_KEY_LEFT)
	{
		ellipse_x=ellipse_x-speed;
		brec_x=brec_x-speed;
		srec_x=srec_x-speed;
	}

	//place your codes for other keys here
}
 void iFire()
 {
	 fire_y=fire_y+10;
	 if(fire_y>572)
		 fire=0;
 
 }
 void efire()
 {
	 efire_y=efire_y-8;
	 if(efire_y<0)
	 {
		 efire_y=erec11_y;
		 efire_x=erec11_x;
	 }
 }
 void e2fire()
 {
	 e2fire_y=e2fire_y-8;
	 if(e2fire_y<0)
	 {
		 e2fire_y=erec21_y;
		 e2fire_x=erec21_x;
	 }
 }

 void enemy1()
 {
	 enemy=1;
	 ch1=ch;
	 
	 
	 efire_x=erec11_x;
	 efire_y=erec11_y;
	 
	 occurance=occurance+1;
	 if(occurance%5==0)
	 {
		 erec11_x=ellipse_x+10;
		 erec11_y=562;
		 erec12_x=erec11_x-11;
		 erec12_y=572;
	 }
	 if(occurance%5==1)
	 {
		 erec11_x=ellipse_x+300;
		 erec11_y=562;
		 erec12_x=erec11_x-11;
		 erec12_y=572;
	 }



	if(occurance%5==2)
	 {
		 erec11_x=ellipse_x-200;
		 erec11_y=562;
		 erec12_x=erec11_x-11;
		 erec12_y=572;
	 }
	 if(occurance%5==3)
	 {
		 erec11_x=ellipse_x+150;
		 erec11_y=562;
		 erec12_x=erec11_x-11;
		 erec12_y=572;
	 }

	if(occurance%5==4)
	 {
		 erec11_x=ellipse_x+250;
		 erec11_y=562;
		 erec12_x=erec11_x-11;
		 erec12_y=572;
	 }
}
void enemy22()
{
	enemy2=1;
	o=o+1;
	ch2=ch;
	
	e2fire_x=erec21_x;
	e2fire_y=erec21_y;
	if(o%5==0)
	{
		erec21_x=ellipse_x-25;
		erec21_y=562;
		erec22_x=erec21_x-11;
		erec22_y=572;
	}
	if(o%5==1)
	{
		erec21_x=ellipse_x-100;
		erec21_y=562;
		erec22_x=erec21_x-11;
		erec22_y=572;
	}
	if(o%5==2)
	{
		erec21_x=ellipse_x+20;
		erec21_y=562;
		erec22_x=erec21_x-11;
		erec22_y=572;
	}
	if(o%5==3)
	{
		erec21_x=ellipse_x-150;
		erec21_y=562;
		erec22_x=erec21_x-11;
		erec22_y=572;
	}
	if(o%5==4)
	{
		erec21_x=ellipse_x-200;
		erec21_y=562;
		erec22_x=erec21_x-11;
		erec22_y=572;
	}
}

 void eplane()
 {
	 if(erec11_x>650)
		 ch1=-ch;
	 if(erec11_x<200)
		 ch1=ch;
	 if(enemy==1)
	 {
		 
		 
		erec11_x=erec11_x+ch1;
		erec12_x=erec12_x+ch1;
		
		
		 erec11_y=erec11_y-2;
		 erec12_y=erec12_y-2;
		 
	}
 }
 void eplane2()
 {
	if(erec21_x>600)
		 ch2=-ch;;
	 if(erec21_x<150)
		 ch2=ch;
	if(enemy2==1)
	 {
		 
		 
		erec21_x=erec21_x+ch2;
		erec22_x=erec22_x+ch2;
		
		 erec21_y=erec21_y-2;
		 erec22_y=erec22_y-2;
		 
	}
	
 }

 void iBang()
 {
	 if(bang>0)
	 {
		 bang=bang+1;
		 if(enemy!=0)
		 {
			 bang_x=ellipse_x;
			bang_y=ellipse_y;
		 }
		 else
		 {
			bang_x=erec12_x;
			 bang_y=erec12_y+5;
		 }
			bang_r=bang_r+1;
		 
		 if(bang>25)
		 {
			 bang=0;
			 bang_r=10;
			 myplane=1;
		 }
	 }
 }
 
 void iBang2()
 {
	 if(bang2>0)
	 {
		 bang2=bang2+1;
		 if(enemy2!=0)
		 {
			 bang2_x=ellipse_x;
			bang2_y=ellipse_y;
		 }
		 else
		 {
			bang2_x=erec22_x;
			 bang2_y=erec22_y+5;
		 }
			bang2_r=bang2_r+1;
		 
		 if(bang2>25)
		 {
			 bang2=0;
			 bang2_r=10;
			 myplane=1;
		 }
	 }
 }
 void ibg()
 {
	 bg_y=bg_y-1;
	 if(bg_y<0)
		 bg_y=512;
 }







int main()
{
	//place your own initialization codes here. 
	
	iSetTimer(30,iFire);
	iSetTimer(7000,enemy1);
	iSetTimer(5,eplane);
	iSetTimer(10,iBang);
	iSetTimer(5500,enemy22);
	iSetTimer(5,eplane2);
	iSetTimer(30,efire);
	iSetTimer(10,iBang2);
	iSetTimer(30,e2fire);
	iSetTimer(10,ibg);
	ellipse_x=200;
	ellipse_y=200;
	srec_x=198;
	srec_y=210;
	brec_x=175;
	brec_y=196;

	iInitialize(1024, 512, "demooo");
	return 0;
}	