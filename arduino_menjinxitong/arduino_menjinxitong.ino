#include <SPI.h>
#include <RFID.h>
#include <Ethernet.h>
#include <Wire.h>
#include <EEPROM.h>
//RFID rfid(10, 9);  //实例化一个读卡器，10是读卡器SS引脚、9是读卡器RST引脚
RFID rfid(49,47);
#define Host 2//要修改门禁权限就修改这里
boolean u = 0;
int    CS   = 31;      /* 定义LCD片选线 */
int    DATA = 32;      /* 定义LCD数据线 */
int    CLK  = 33;      /* 定义LCD时钟线 */
int k1 = 4;  //定义按键接口
int key = 0;//定义键值
union data
{
    byte b[4];
};
data col;
int addr = 0;
void setup()
{
    /*pinMode(2, OUTPUT); //绿灯（如果读出的卡是对的，那么就亮绿灯）
      pinMode(3, OUTPUT);//红灯（如果读出的卡是错的，那么就亮红灯）
      pinMode(4, OUTPUT);*/
    Wire.begin();
    Serial.begin(9600);
    SPI.begin();
    rfid.init();
    pinMode(CS, OUTPUT);
    pinMode(DATA, OUTPUT);
    pinMode(CLK, OUTPUT);
    initial_LCD1602() ;
    pinMode(k1, INPUT);
    pinMode(4,OUTPUT);
    pinMode(53,OUTPUT);
    digitalWrite(4,HIGH);
    digitalWrite(53,HIGH);
}


/********************************************************************/
//1602液晶初始化
void initial_LCD1602()
{
    int rs=LOW;
    LCD_Command_Write(rs,0x01);//0x01清屏:数据指针清零,所有显示清零
    delay(2);
    LCD_Command_Write(rs,0x06);//0x06写入新数据后光标右
    LCD_Command_Write(rs,0x0c);//0x0C显示功能开，无光标，光标不闪烁
    LCD_Command_Write(rs,0x14);//0x14光标右移1格，且AC值加1
    LCD_Command_Write(rs,0x38);//0x38数据总线为8位，显示2行，5 ×7点阵/每字符
}
void loop()
{
    int cmp1;
    int cmp2;
    //if (rfid.isCard()) {//读到了卡
    /*Serial.print("The card's number is  : ");
      Serial.print(rfid.serNum[0], HEX);
      Serial.print(" ");
      Serial.print(rfid.serNum[1], HEX);
      Serial.print(" ");
      Serial.print(rfid.serNum[2], HEX);
      Serial.print(" ");
      Serial.print(rfid.serNum[3], HEX);
      Serial.print(" ");
      Serial.print(rfid.serNum[4], HEX);
      Serial.println(" ");*/
    while(1)
    {
        while(!digitalRead(k1))
        {
            if (!digitalRead(k1) )
            {
              clear();
              delay(100);
                if (rfid.isCard())
                {
                    if (rfid.readCardSerial())
                    {
                        cmp1 = compare();
                        /*
                   if (!u) { //如果读到的卡不在列表中，那么执行下面程序
                          digitalWrite(3, HIGH);//红灯亮，不放行
                          tone(4, 200);//播放错误声
                          lcd.clear();//清屏，为了报错
                          lcd.home();
                          lcd.print("Unkonw card");
                          delay(700);
                          digitalWrite(3, LOW);
                          noTone(4);
                          delay(300);
                          lcd.clear();
                          lcd.home();
                          lcd.print("Put card here");*/
                        if(cmp1 == 0)
                        {
                            clear();
                            LCD_n();
                            LCD_Write_String(2,1,"success");
                            eepromwrite();
                            delay(2000);
                            clear();
                        }
                        else if(cmp1 == 1)
                        {
                            clear();
                            LCD_n();
                            LCD_Write_String(2,1,"failed-has-registed");
                            delay(2000);
                            clear();
                        }
                    }
                    rfid.selectTag(rfid.serNum);
                }
                rfid.halt();
            }
        }
        if( digitalRead(k1))
        {
            if (rfid.isCard())
            {
                if (rfid.readCardSerial())
                {
                    cmp2 = compare();
                    if(cmp2 == 1)
                    {
                        clear();
                        LCD_n();
                        LCD_Write_String(2,1,"yes");
                        delay(2000);
                        clear();
                    }
                    else if(cmp2 == 0)
                    {
                        clear();
                        LCD_n();
                        LCD_Write_String(2,1,"no");
                        delay(2000);
                        clear();
                    }
                }
                rfid.selectTag(rfid.serNum);
            }
            rfid.halt();
        }
    }
}
int Findhehe(int m)
{
    int j=0,n=m;
    while(n)
    {
        n=n/10;
        j++;
    }
    return j;
}
void LCD_Command_Write( int rs, int command)// LCD指令控制,
{
    int i;
//同步 CS→0→1
    digitalWrite(CS, LOW); //CS
    delayMicroseconds(100);
    digitalWrite(CS, HIGH); //CS
//起始位 =1
    digitalWrite(CLK, LOW);//CLK
    digitalWrite(DATA, HIGH);//=1
    digitalWrite(CLK, HIGH);
//RS
    digitalWrite(CLK, LOW);//CLK
    digitalWrite(DATA, rs);//RS=
    digitalWrite(CLK, HIGH);
//DATA D7……D0
    for(i = 0; i < 8; i++)
    {
        digitalWrite(CLK, LOW);
        digitalWrite(DATA, bitRead(command, 7- i));
        digitalWrite(CLK, HIGH);
    }
// 时钟下降沿触发，写入数据
    delayMicroseconds(100);
    digitalWrite(CLK, LOW);
}
/********************************************************************/
void LCD_SET_XY( int x, int y )//设置光标位置,X为横,Y为竖
{
    int address;
    int rs=LOW;
    if    (y ==0) address = 0x80 + x;//0x80+ 地址,设置LCD第一行的数据指针初始地址,表示在1602第一行显示
    else          address = 0xc0 + x;//0xc0+ 地址,设置LCD第二行的数据指针初始地址,表示在1602第二行显示
    LCD_Command_Write(rs,address);
}
//定位显示ASCII码字符
void LCD_Write_Char( int x,int y,int dat)
{
    LCD_SET_XY( x, y );
    int rs=HIGH;
    LCD_Command_Write(rs,dat);
}
/********************************************************************/
//定位显示字符串
void LCD_Write_String(int X,int Y,char *s)//打印*s,X为横,Y为竖,*s为输出字符
{
    LCD_SET_XY( X, Y );    //设置地址
    while (*s)             //写字符串
    {
        int  rs=HIGH;
        LCD_Command_Write(rs, *s);
        s ++;
    }
}
void LCD_n()
{
    byte a[5];
    int shuwei,i,j;
    int p,q,rs;
    rs=LOW;
    LCD_Command_Write(rs, 0x80);
    rs=HIGH;
    for(j = 0; j < 5; j++)
    {
        p=rfid.serNum[j];
        shuwei=Findhehe(p);
        for(i=0; i<=shuwei-1; i++ )
        {
            q=p;
            p=p/10;
            a[i]=q-p*10;

        }
        for(i=shuwei-1; i>=0; i-- )
        {
            LCD_Command_Write(rs, a[i]+0x30);
        }
    }
    LCD_Command_Write(rs, 0x20);
    LCD_Command_Write(rs, 0x20);
    LCD_Command_Write(rs, 0x20);
}
void clear()
{
    LCD_Write_String(0,0,"                ");
    LCD_Write_String(0,1,"                ");
}
void eepromwrite() //
{
  int a;
  a = EEPROM.read(0);
  Serial.print("a=");
  Serial.println(a);
  EEPROM.write(a * 5 + 5, rfid.serNum[0]);
  EEPROM.write(a * 5 + 6, rfid.serNum[1]);
  EEPROM.write(a * 5 + 7, rfid.serNum[2]);
  EEPROM.write(a * 5 + 8, rfid.serNum[3]);
  EEPROM.write(a * 5 + 9, rfid.serNum[4]);
  EEPROM.write(0, ++a);
}
int compare()
{
  int flag = 0;
  int j;
  int r = EEPROM.read(0);
  for (j = 1; j <= r; j++)
  {
    if ((rfid.serNum[0] == EEPROM.read(j * 5)) && (rfid.serNum[1] == EEPROM.read(j * 5 + 1))
        && (rfid.serNum[2] == EEPROM.read(j * 5 + 2)) && (rfid.serNum[3] == EEPROM.read(j * 5 + 3))
        && (rfid.serNum[4] == EEPROM.read(j * 5 + 4)))
    {
      return 1;
    }
  }
  return 0;
}
