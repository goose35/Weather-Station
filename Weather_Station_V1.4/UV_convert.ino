//------------------------------------------------------------------------------------------------------------
/////////////////////////////////////////////UV_convert //////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------------------
void UV_convert()

{
  if(UVmax < 0.9)
   UVmax = 0;
  else if(UVmax >= 0.9 && UVmax < 1.75)
   UVmax = 1;  
  else if(UVmax >= 1.75 && UVmax < 2.4)
   UVmax = 2;
  else if(UVmax >= 2.4 && UVmax < 3.4)
   UVmax = 3;
  else if(UVmax >= 3.4 && UVmax < 4.4)
   UVmax = 4;
  else if(UVmax >= 4.4 && UVmax < 5.4)
   UVmax = 5;
  else if(UVmax >= 5.4 && UVmax < 6.4)
   UVmax = 6;
  else if(UVmax >= 6.4 && UVmax < 7.4)
   UVmax = 7;
  else if(UVmax >= 7.4 && UVmax < 8.4)
   UVmax = 8;
  else if(UVmax >= 8.4 && UVmax < 9.4)
   UVmax = 9;
  else if(UVmax >= 9.4 && UVmax < 10.4)
   UVmax = 10;
  else if(UVmax >= 10.4 && UVmax < 11.4)
   UVmax = 11;
  else if(UVmax >= 11.4 && UVmax < 12.4)
   UVmax = 12;
  else if(UVmax >= 12.4 && UVmax < 13.4)
   UVmax = 13;
  else if(UVmax >= 13.4 && UVmax < 14.4)
   UVmax = 14;
  else if(UVmax >= 14.4 )
   UVmax = 15;
}
