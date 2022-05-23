/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 1/23/2022
Author  : PARSA VARES
Company : SRBIAU
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <lcd.h>
#include <stdio.h>
#include <math.h>
#include <keypad.h>
#include <inputNum.h>
#include <delay.h>
#define xtal 8000000
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
//--------------------------
    char op,last_op,dis;
    float ans,a,b;
    char buffer[40];
     float m;
//--------------------------
    char ma_error[]="Ma ERROR";
    //char syn_error[]="Syntax ERROR";
//--------------------------

 void display1 (){
    lcd_clear();
    sprintf(buffer,"%f\n%f",a,ans);
    lcd_puts(buffer);
    dis=1;
 }
  
 void display2 (){
    op=last_op;
    lcd_clear();
    sprintf(buffer,"%.2f%c%.2f\n%f",a,op,b,ans);
    lcd_puts(buffer);
    dis=1;
 }
 
  void display3 (unsigned char sign_char){
    lcd_clear();
    lcd_write_byte(0x80,sign_char);
    sprintf(buffer,"%f\n%f",a,ans);
    lcd_puts(buffer);
    dis=1;
 }
 
  void display4 (float m){
    lcd_clear();
    sprintf(buffer,"MEMORY\nM=%f",m);
    lcd_puts(buffer);
    dis=1;
 }        
  /* void display5 (float m){
    lcd_clear();
    sprintf(buffer,"MEMORY2\nM=%f",m);
    lcd_puts(buffer);
    dis=1;
 }                 */
  
 void equal(){   // =
   ans=a;
   display1();  
    //display5(); 
    }
 
  void may_error(){
      lcd_clear();
      lcd_gotoxy(6,0);
      lcd_puts(ma_error);
      dis=1;
 }
 
 void clear_var(){
    ans=a=b=op=last_op=0;
    lcd_clear();
    lcd_gotoxy(19,1);
    lcd_putchar('0');
    lcd_gotoxy(0,0);
    _lcd_ready();
    _lcd_write_data(0x0f);
 } 
 
 void calculat_add(){     //+
  b=input_digit();
  ans=a+b; 
  display2(); 
    //display5();
 }  

 void calculat_min(){    //-
  b=input_digit();
  ans=a-b;
  display2();   
  //display5();
 } 

 void calculat_mul(){      //*
  b=input_digit();   
  ans=a*b;
  display2();
    //display5();
 }
 
  void calculat_div(){       // /
  b=input_digit();
    if(b==0){
        may_error();
    }else{
     ans=a/b;
     display2();
   }
    //display5();
 }
 
  void calculat_squ(){        //s
  if(a<0){
    may_error();
   }else{
    ans=sqrt(a);
    display3(0xE8); //E8 on datasheet LCD is code signe square 
   }
    //display5();
 } 
  
  void inc_memory(){           //i
  m+=ans;
  display4(m); 
 // display5(M2);
 }
 
 void dec_memory(){             //d
  m-=ans;
  display4(m);
 // display5(M2);
 }
 
 void calculat_percent(){         //%
 //  b=input_digit();
   ans=(a/100);
   display2(); 
   //display5();
 }
 
 void memory_clear(){      //m
  m=0;
  display4(m);    
 // display5(M2);
 }
 
   
 void main(void){
    lcd_init(20); 
    clear_var();
    
   while (1){
    a=input_digit();
    last_op=op;
    
     switch(op){
       case '=': 
       equal();
       break;
       
       case 'c': 
       clear_var();
       break;
       
       case '+': 
       calculat_add();
       break;
       
       case '-': 
       calculat_min();
       break;
       
       case '*': 
       calculat_mul();
       break;
       
       case '/': 
       calculat_div();
       break;
       
       case 's': //square
       calculat_squ();
       break;
       
       case 'i': //increment memory
       inc_memory();
       break;
       
       case 'd': //decrement memory
       dec_memory();
       break;
       
       case 'm': //show memory
       memory_clear();
       break;
       
       case '%': //percent
       calculat_percent();
       break;   
     }
     op=0;
   }
 } 