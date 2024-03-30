#------------------------ Tool Specifications & Options ----------------------

COMPILER  =  lcc

CC        =  "C:\Program Files\MATLAB\R2022a\sys\lcc64\lcc64\bin\lcc64.exe"
LD        =  "C:\Program Files\MATLAB\R2022a\sys\lcc64\lcc64\bin\lcclnk64.exe"
LIBCMD    =  "C:\Program Files\MATLAB\R2022a\sys\lcc64\lcc64\bin\lcclib64.exe"
CFLAGS    =  -dll -noregistrylookup  -c -Zp8 -DLCC_WIN64 -DMATLAB_MEX_FILE -nodeclspec
LDFLAGS   =  -s -dll -entry LibMain HmMWlK9Dm6sKcmNAufKISE_cclib.def -L"C:\Program Files\MATLAB\R2022a\sys\lcc64\lcc64\lib64"

OBJECTS = \
	   slcc_interface_HmMWlK9Dm6sKcmNAufKISE.obj \
	   lccstub.obj \

STATICLIBS = \

#------------------------------ Include/Lib Path ------------------------------

INCLUDE_PATH = \
     -I"c:\program files\matlab\r2022a\extern\include" \
     -I"c:\program files\matlab\r2022a\simulink\include" \
     -I"c:\users\joser\onedrive\documentos\github\etas\main_ecu\simulink_c\slprj\_slcc\hmmwlk9dm6skcmnaufkise" \
     -I"c:\users\joser\onedrive\desktop\nueva carpeta\c" \
     -I"c:\users\joser\onedrive\documentos\github\etas\main_ecu\simulink_c" \
     -I"c:\users\joser\onedrive\desktop\nueva carpeta" \
     -I"c:\program files\matlab\r2022a\sys\lcc64\lcc64\include64" \
     -I"c:\program files\matlab\r2022a\sys\lcc64\lcc64\mex" \

#--------------------------------- Rules --------------------------------------

HmMWlK9Dm6sKcmNAufKISE_cclib.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) /OUT:HmMWlK9Dm6sKcmNAufKISE_cclib.dll $(OBJECTS)  $(STATICLIBS) "C:\Program Files\MATLAB\R2022a\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2022a\extern\lib\win64\microsoft\libmx.lib"
slcc_interface_HmMWlK9Dm6sKcmNAufKISE.obj :	C:\Users\joser\OneDrive\DOCUME~1\GitHub\ETAS\Main_ECU\SIMULI~1\slprj\_slcc\HMMWLK~1\SLCC_I~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Users\joser\OneDrive\Documentos\GitHub\ETAS\Main_ECU\Simulink_C\slprj\_slcc\HmMWlK9Dm6sKcmNAufKISE\slcc_interface_HmMWlK9Dm6sKcmNAufKISE.c"
lccstub.obj :	C:\PROGRA~1\MATLAB\R2022a\sys\lcc64\lcc64\mex\lccstub.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2022a\sys\lcc64\lcc64\mex\lccstub.c"
