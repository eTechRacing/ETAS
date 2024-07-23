clear all
clc

car = struct();%Definiciones del coche

g=9.81; %m/s^2

car.l=1.53; %longitud cotxe
car.a = 0.8;%Distancia ruedas del a cg
car.b = car.l-car.a;%Distancia ruedas tras a cg
car.Tf = 1.25;%Trackwith front
car.Tr = 1.15;%Trackwith rear
car.weight = 200+86; %Pes
car.Zrf=0.0963; %Roll center front
car.Zrr=0.12; %Roll center rear
car.H=0.1837;
car.Kf= 336.38; %roll stiffnes front
car.Kr= 313.41; %roll stiffnes rear
car.h= 0.28; 
car.copx=0.84; %centre de pressions
car.lambdaHy=1;
car.lambdaVy=1;
car.lambdauy=0.6; %scaling factor
car.lambdaKygamma=1;
car.lambdaCy=1;
car.lambdaEy=1;
car.lambdaKyalpha=1;
car.lambdaKygamma=1;
car.PF=0.75; %Front pressure Bar
car.PR=0.75; %Rrear pressure Bar
gammaF0=-1.5; %Front Camber deg
gammaR0=-1; %Rear Camber deg

tire = struct();%Valores adimensionales modelo de neumatico
tire.PCY1 = 1.5000; %shape factor (Afilar cantonades i estirar i atxatar)
tire.PDY1 = 2.35; %estirar o aixafar gràfica
tire.PDY2 = -0.4982;
tire.PDY3 = 10;
tire.PEY1 = -0.0028; %afilar cantonades
tire.PEY2 = 0.0019;
tire.PEY3 = -1.5129; %en negatiu s'afila la dreta i en postiu l'esquerra
tire.PEY4 = 230.59;
tire.PEY5 = -3.8505e+04;
tire.PKY1 = -25.5913;
tire.PKY2 = 1; %rotar sobre el centre antihorari
tire.PKY3 = 1.0000; 
tire.PKY4 = 2.0000; 
tire.PKY5 = -1.7614; 
tire.PKY6 = 4.1319;
tire.PKY7 = 2.4839;
tire.PHY1 = 0; %Desplaçar lateralment
tire.PHY2 = 0; %Desplaçar lateralment
tire.PVY1 = 0; %pujar i baixar la grafica sencera
tire.PVY2 = 0; %pujar i baixar la grafica sencera
tire.PVY3 = 0; %pujar i baixar la grafica sencera
tire.PVY4 = 2.9407;
tire.PPY1 = 0.2347; 
tire.PPY2 = 0.9613;
tire.PPY3 = -1.0855;
tire.PPY4 = -2;
tire.PPY5 = 0.0000;
tire.Fz0 = 1080;
tire.P0=0.97;
%Turn slip
z0=1;
z1=1;
z2=1;
z3=1;
z4=1;

%Ecuacio MZ(SA) Regressio 
a0m =       2.107;
a1m =      -3.933;
b1m =       61.61;
a2m =     -0.4837;
b2m =       10.06;
a3m =      0.7475;
b3m =        7.31;
a4m =      0.4277;
b4m =      -0.423;
a5m =       1.124;
b5m =       3.801;
wm =      0.2417;

MZ=@(SA)  a0m + a1m*cos(SA*wm) + b1m*sin(SA*wm) + a2m*cos(2*SA*wm) + b2m*sin(2*SA*wm) + a3m*cos(3*SA*wm) + b3m*sin(3*SA*wm) + a4m*cos(4*SA*wm) + b4m*sin(4*SA*wm) + a5m*cos(5*SA*wm) + b5m*sin(5*SA*wm);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Imputs
Radi=9.125; %Radi de gir
deltadg=0:1:18;%Steering angles en graus
SI=deltadg'.*pi/180; %Steering angle en rad
R=sign(SI)*Radi;
Betadg=0:1:9; %Slip angle en graus
VS=Betadg'.*pi/180; %Slip angle rad
sliplim=15*pi/180; %Limit slip angle


%Izz=car.weight*(car.a^2+car.h^2); %Moment inercia
Wf=g*car.weight*car.b/(car.l);
Wr=g*car.weight*car.a/(car.l);


for i = 1:length(SI);
    Q=0; %es pel loop dels VS
    for j = 1:length(VS); 
        if Q==0
            w(i,j)=0.0000000001;
            Ay(i,j)=0;
            for k=1:10     
                
                df(i,j)=1.93*(w(i,j)*R(i)).^2; %Down Force
                dfR(i,j)=df(i,j)*car.copx/(1.53*2); %Down Force front
                dfF(i,j)=df(i,j)*(1.53-car.copx)/(1.53*2); %Down Force rear

                alphaFL(i,j)=((tan(VS(j))*(w(i,j)*R(i)))+(w(i,j)*car.a))./((w(i,j)*R(i))-w(i,j)*car.Tf/2)-SI(i); %slip angle front right en rad
                %alphaFL(i,j)=((tan(VS(j))*R)+car.a)./(R-car.Tf/2)-SI(i); %slip angle front left en rad
                if alphaFL(i,j)>sliplim;
                    alphaFL(i,j)=sliplim;
                elseif alphaFL(i,j)<-sliplim;
                    alphaFL(i,j)=-sliplim;
                end

                alphaFR(i,j)=((tan(VS(j))*(w(i,j)*R(i)))+(w(i,j)*car.a))./((w(i,j)*R(i))+w(i,j)*car.Tf/2)-SI(i); %slip angle front right en rad
                if alphaFR(i,j)>sliplim;
                    alphaFR(i,j)=sliplim;
                elseif alphaFR(i,j)<-sliplim;
                    alphaFR(i,j)=-sliplim;
                end

                alphaRL(i,j)=((tan(VS(j))*(w(i,j)*R(i)))-(w(i,j)*car.b))./((w(i,j)*R(i))-w(i,j)*car.Tr/2); %slip angle rear left en rad           
                if alphaRL(i,j)>sliplim;
                    alphaRL(i,j)=sliplim;
                elseif alphaRL(i,j)<-sliplim;
                    alphaRL(i,j)=-sliplim;
                end

                alphaRR(i,j)=((tan(VS(j))*(w(i,j)*R(i)))-(w(i,j)*car.b))./((w(i,j)*R(i))+w(i,j)*car.Tr/2); %slip angle rear right en rad
                if alphaRR(i,j)>sliplim;
                    alphaRR(i,j)=sliplim;
                elseif alphaRR(i,j)<-sliplim;
                    alphaRR(i,j)=-sliplim;
                end

                %Weight transfer
                WF(i,j)=Ay(i,j)*((g*car.weight/car.Tf)*((car.H*car.Kf/(car.Kf+car.Kr))+(car.b*car.Zrf/car.l))); %weight transfer front (La Ay es en g)
                WR(i,j)=Ay(i,j)*((g*car.weight/car.Tr)*((car.H*car.Kr/(car.Kf+car.Kr))+(car.a*car.Zrr/car.l))); %weight transfer rear (La Ay es en g)

                WFL(i,j)=WF(i,j);
                WFR(i,j)=-WF(i,j);
                WRL(i,j)=WR(i,j);
                WRR(i,j)=-WR(i,j);

                %Camber variation
                rollangle(i,j)=Ay(i,j)*car.weight*g*car.H/(car.Kr+car.Kf);
                gammaFL(i,j)=abs((gammaF0+0.55333*rollangle(i,j))*pi/180); %rollangle i camber en deg 
                gammaFR(i,j)=abs((gammaF0-0.55333*rollangle(i,j))*pi/180); %rollangle i camber en deg 
                gammaRL(i,j)=abs((gammaR0+0.55333*rollangle(i,j))*pi/180); %rollangle i camber en deg 
                gammaRR(i,j)=abs((gammaR0-0.55333*rollangle(i,j))*pi/180); %rollangle i camber en deg 


                %Front Left wheel
                FzFL(i,j) = (g*car.weight*car.b/(car.l*2))+WFL(i,j)+dfF(i,j);
                dfzFL(i,j)=(FzFL(i,j)-tire.Fz0)./tire.Fz0;
                dpiFL=(car.PF-tire.P0)/tire.P0;
                Shy0FL(i,j)=(tire.PHY1+tire.PHY2*dfzFL(i,j))*car.lambdaHy;
                Svy0FL(i,j)=FzFL(i,j)*(tire.PVY1+tire.PVY2*dfzFL(i,j))*car.lambdaVy*car.lambdauy*z2;
                SvygammaFL(i,j)=FzFL(i,j)*(tire.PVY3+tire.PVY4*dfzFL(i,j))*gammaFL(i,j)*car.lambdaKygamma*car.lambdauy*z2;
                SvyFL(i,j)=Svy0FL(i,j)+SvygammaFL(i,j);
                Kygamma0FL(i,j)=(tire.PKY6+tire.PKY7*dfzFL(i,j))*FzFL(i,j)*car.lambdaKygamma*(1+tire.PPY5*dpiFL);
                Kyalpha0FL(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiFL)*sin(tire.PKY4*atan(FzFL(i,j)/((tire.PKY2*tire.Fz0*(1+tire.PPY2*dpiFL)))))*car.lambdaKyalpha;
                KyalphaFL(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiFL)*sin(tire.PKY4*atan(FzFL(i,j)/((tire.PKY2+tire.PKY5*gammaFL(i,j)^2)*tire.Fz0*(1+tire.PPY2*dpiFL))))*(1-tire.PKY3*abs(gammaFL(i,j)))*car.lambdaKyalpha*z3;
                ShygammaFL(i,j)=((Kygamma0FL(i,j)*gammaFL(i,j)-SvygammaFL(i,j))/KyalphaFL(i,j))*z0+z4-1;
                ShyFL(i,j)=Shy0FL(i,j)+ShygammaFL(i,j);
                alphayFL(i,j)=-(alphaFL(i,j)+ShyFL(i,j));
                CyFL(i,j)=tire.PCY1*car.lambdaCy;
                uyFL(i,j)=(tire.PDY1+tire.PDY2*dfzFL(i,j))*(1+tire.PPY3*dpiFL+tire.PPY4*dpiFL^2)*(1-tire.PDY3*gammaFL(i,j)^2)*car.lambdauy;
                DyFL(i,j)=uyFL(i,j)*FzFL(i,j)*z2;
                EyFL(i,j)=(tire.PEY1+tire.PEY2*dfzFL(i,j))*(1+tire.PEY5*gammaFL(i,j)^2-(tire.PEY3+tire.PEY4*gammaFL(i,j))*sign(alphayFL(i,j)))*car.lambdaEy;
                ByFL(i,j)=KyalphaFL(i,j)/(CyFL(i,j)*DyFL(i,j));
                FypFL(i,j)=DyFL(i,j)*sin(CyFL(i,j)*atan(ByFL(i,j)*alphayFL(i,j)-EyFL(i,j).*(ByFL(i,j)*alphayFL(i,j)-atan(ByFL(i,j)*alphayFL(i,j)))))+SvyFL(i,j);
                %MF61Y:
                Gxalpha=1;%combined slip weiht function
                Svyk=0;%combined slip braking included
                FyFL(i,j)=-Gxalpha*FypFL(i,j)+Svyk;


                %Front Right wheel
                FzFR(i,j) = (g*car.weight*car.b/(car.l*2))+WFR(i,j)+dfF(i,j);
                dfzFR(i,j)=(FzFR(i,j)-tire.Fz0)./tire.Fz0;
                dpiFR=(car.PF-tire.P0)/tire.P0;
                Shy0FR(i,j)=(tire.PHY1+tire.PHY2*dfzFR(i,j))*car.lambdaHy;
                Svy0FR(i,j)=FzFR(i,j)*(tire.PVY1+tire.PVY2*dfzFR(i,j))*car.lambdaVy*car.lambdauy*z2;
                SvygammaFR(i,j)=FzFR(i,j)*(tire.PVY3+tire.PVY4*dfzFR(i,j))*gammaFR(i,j)*car.lambdaKygamma*car.lambdauy*z2;
                SvyFR(i,j)=Svy0FR(i,j)+SvygammaFR(i,j);
                Kygamma0FR(i,j)=(tire.PKY6+tire.PKY7*dfzFR(i,j))*FzFR(i,j)*car.lambdaKygamma*(1+tire.PPY5*dpiFR);
                Kyalpha0FR(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiFR)*sin(tire.PKY4*atan(FzFR(i,j)/((tire.PKY2*tire.Fz0*(1+tire.PPY2*dpiFR)))))*car.lambdaKyalpha;
                KyalphaFR(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiFR)*sin(tire.PKY4*atan(FzFR(i,j)/((tire.PKY2+tire.PKY5*gammaFR(i,j)^2)*tire.Fz0*(1+tire.PPY2*dpiFR))))*(1-tire.PKY3*abs(gammaFR(i,j)))*car.lambdaKyalpha*z3;
                ShygammaFR(i,j)=((Kygamma0FR(i,j)*gammaFR(i,j)-SvygammaFR(i,j))/KyalphaFR(i,j))*z0+z4-1;
                ShyFR(i,j)=Shy0FR(i,j)+ShygammaFR(i,j);
                alphayFR(i,j)=alphaFR(i,j)+ShyFR(i,j);
                CyFR(i,j)=tire.PCY1*car.lambdaCy;
                uyFR(i,j)=(tire.PDY1+tire.PDY2*dfzFR(i,j))*(1+tire.PPY3*dpiFR+tire.PPY4*dpiFR^2)*(1-tire.PDY3*gammaFR(i,j)^2)*car.lambdauy;
                DyFR(i,j)=uyFR(i,j)*FzFR(i,j)*z2;
                EyFR(i,j)=(tire.PEY1+tire.PEY2*dfzFR(i,j))*(1+tire.PEY5*gammaFR(i,j)^2-(tire.PEY3+tire.PEY4*gammaFR(i,j))*sign(alphayFR(i,j)))*car.lambdaEy;
                ByFR(i,j)=KyalphaFR(i,j)/(CyFR(i,j)*DyFR(i,j));
                FypFR(i,j)=DyFR(i,j)*sin(CyFR(i,j)*atan(ByFR(i,j)*alphayFR(i,j)-EyFR(i,j).*(ByFR(i,j)*alphayFR(i,j)-atan(ByFR(i,j)*alphayFR(i,j)))))+SvyFR(i,j);
                %MF61Y:
                Gxalpha=1;%conbined slip weiht function
                Svyk=0;%conbined slip braking included
                FyFR(i,j)=Gxalpha*FypFR(i,j)+Svyk;


                %Rear Left wheel
                FzRL(i,j) = (g*car.weight*car.a/(car.l*2))+WRL(i,j)+dfR(i,j);
                dfzRL(i,j)=(FzRL(i,j)-tire.Fz0)./tire.Fz0;
                dpiRL=(car.PR-tire.P0)/tire.P0;
                Shy0RL(i,j)=(tire.PHY1+tire.PHY2*dfzRL(i,j))*car.lambdaHy;
                Svy0RL(i,j)=FzRL(i,j)*(tire.PVY1+tire.PVY2*dfzRL(i,j))*car.lambdaVy*car.lambdauy*z2;
                SvygammaRL(i,j)=FzRL(i,j)*(tire.PVY3+tire.PVY4*dfzRL(i,j))*gammaRL(i,j)*car.lambdaKygamma*car.lambdauy*z2;
                SvyRL(i,j)=Svy0RL(i,j)+SvygammaRL(i,j);
                Kygamma0RL(i,j)=(tire.PKY6+tire.PKY7*dfzRL(i,j))*FzRL(i,j)*car.lambdaKygamma*(1+tire.PPY5*dpiRL);
                Kyalpha0RL(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiRL)*sin(tire.PKY4*atan(FzRL(i,j)/((tire.PKY2*tire.Fz0*(1+tire.PPY2*dpiRL)))))*car.lambdaKyalpha;
                KyalphaRL(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiRL)*sin(tire.PKY4*atan(FzRL(i,j)/((tire.PKY2+tire.PKY5*gammaRL(i,j)^2)*tire.Fz0*(1+tire.PPY2*dpiRL))))*(1-tire.PKY3*abs(gammaRL(i,j)))*car.lambdaKyalpha*z3;
                ShygammaRL(i,j)=((Kygamma0RL(i,j)*gammaRL(i,j)-SvygammaRL(i,j))/KyalphaRL(i,j))*z0+z4-1;
                ShyRL(i,j)=Shy0RL(i,j)+ShygammaRL(i,j);
                alphayRL(i,j)=-(alphaRL(i,j)+ShyRL(i,j));
                CyRL(i,j)=tire.PCY1*car.lambdaCy;
                uyRL(i,j)=(tire.PDY1+tire.PDY2*dfzRL(i,j))*(1+tire.PPY3*dpiRL+tire.PPY4*dpiRL^2)*(1-tire.PDY3*gammaRL(i,j)^2)*car.lambdauy;
                DyRL(i,j)=uyRL(i,j)*FzRL(i,j)*z2;
                EyRL(i,j)=(tire.PEY1+tire.PEY2*dfzRL(i,j))*(1+tire.PEY5*gammaRL(i,j)^2-(tire.PEY3+tire.PEY4*gammaRL(i,j))*sign(alphayRL(i,j)))*car.lambdaEy;
                ByRL(i,j)=KyalphaRL(i,j)/(CyRL(i,j)*DyRL(i,j));
                FypRL(i,j)=DyRL(i,j)*sin(CyRL(i,j)*atan(ByRL(i,j)*alphayRL(i,j)-EyRL(i,j).*(ByRL(i,j)*alphayRL(i,j)-atan(ByRL(i,j)*alphayRL(i,j)))))+SvyRL(i,j);
                %MF61Y:
                Gxalpha=1;%conbined slip weiht function
                Svyk=0;%conbined slip braking included
                FyRL(i,j)=-Gxalpha*FypRL(i,j)+Svyk;


                %Rear Right wheel
                FzRR(i,j) =(g*car.weight*car.a/(car.l*2))+WRR(i,j)+dfR(i,j);
                dfzRR(i,j)=(FzRR(i,j)-tire.Fz0)./tire.Fz0;
                dpiRR=(car.PR-tire.P0)/tire.P0;
                Shy0RR(i,j)=(tire.PHY1+tire.PHY2*dfzRR(i,j))*car.lambdaHy;
                Svy0RR(i,j)=FzRR(i,j)*(tire.PVY1+tire.PVY2*dfzRR(i,j))*car.lambdaVy*car.lambdauy*z2;
                SvygammaRR(i,j)=FzRR(i,j)*(tire.PVY3+tire.PVY4*dfzRR(i,j))*gammaRR(i,j)*car.lambdaKygamma*car.lambdauy*z2;
                SvyRR(i,j)=Svy0RR(i,j)+SvygammaRR(i,j);
                Kygamma0RR(i,j)=(tire.PKY6+tire.PKY7*dfzRR(i,j))*FzRR(i,j)*car.lambdaKygamma*(1+tire.PPY5*dpiRR);
                Kyalpha0RR(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiRR)*sin(tire.PKY4*atan(FzRR(i,j)/((tire.PKY2*tire.Fz0*(1+tire.PPY2*dpiRR)))))*car.lambdaKyalpha;
                KyalphaRR(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiRR)*sin(tire.PKY4*atan(FzRR(i,j)/((tire.PKY2+tire.PKY5*gammaRR(i,j)^2)*tire.Fz0*(1+tire.PPY2*dpiRR))))*(1-tire.PKY3*abs(gammaRR(i,j)))*car.lambdaKyalpha*z3;
                ShygammaRR(i,j)=((Kygamma0RR(i,j)*gammaRR(i,j)-SvygammaRR(i,j))/KyalphaRR(i,j))*z0+z4-1;
                ShyRR(i,j)=Shy0RR(i,j)+ShygammaRR(i,j);
                alphayRR(i,j)=alphaRR(i,j)+ShyRR(i,j);
                CyRR(i,j)=tire.PCY1*car.lambdaCy;
                uyRR(i,j)=(tire.PDY1+tire.PDY2*dfzRR(i,j))*(1+tire.PPY3*dpiRR+tire.PPY4*dpiRR^2)*(1-tire.PDY3*gammaRR(i,j)^2)*car.lambdauy;
                DyRR(i,j)=uyRR(i,j)*FzRR(i,j)*z2;
                EyRR(i,j)=(tire.PEY1+tire.PEY2*dfzRR(i,j))*(1+tire.PEY5*gammaRR(i,j)^2-(tire.PEY3+tire.PEY4*gammaRR(i,j))*sign(alphayRR(i,j)))*car.lambdaEy;
                ByRR(i,j)=KyalphaRR(i,j)/(CyRR(i,j)*DyRR(i,j));
                FypRR(i,j)=DyRR(i,j)*sin(CyRR(i,j)*atan(ByRR(i,j)*alphayRR(i,j)-EyRR(i,j).*(ByRR(i,j)*alphayRR(i,j)-atan(ByRR(i,j)*alphayRR(i,j)))))+SvyRR(i,j);
                %MF61Y:
                Gxalpha=1;%conbined slip weiht function
                Svyk=0;%conbined slip braking included
                FyRR(i,j)=Gxalpha*FypRR(i,j)+Svyk;


                %Izz(i,j)=(car.a/car.l)*(FzFL(i,j)+FzFR(i,j))*car.a^2+(car.b/car.l)*(FzRR(i,j)+FzRL(i,j))*car.b^2;
                if Q==0
                    Ay(i,j)=(FyFL(i,j)*(cos(SI(i)))+FyFR(i,j)*(cos(SI(i)))+(FyRR(i,j)+FyRL(i,j)))/(car.weight*g); %Acceleracio lateral o centripeta en g
                end
                %Ay(i,j)=(FyFL(i,j)*(cos(SI(i)-alphaFL(i,j)))+FyFR(i,j)*(cos(SI(i)-alphaFR(i,j)))+(FyRR(i,j)+FyRL(i,j)))/(car.weight*g); %Acceleracio lateral o centripeta
                YawMoment(i,j)=(FyFL(i,j).*cos(SI(i))+FyFR(i,j).*cos(SI(i)))*car.a-(FyRR(i,j)+FyRL(i,j))*car.b +MZ(alphaFL(i,j))+MZ(alphaFR(i,j))+MZ(alphaRL(i,j))+MZ(alphaRR(i,j));
                %YawMoment(i,j)=(FyFL(i,j).*cos(SI(i)-alphaFL(i,j))+FyFR(i,j).*cos(SI(i)-alphaFL(i,j)))*car.a-(FyRR(i,j)+FyRL(i,j))*car.b-MZ(alphaFL(i,j))-MZ(alphaFR(i,j))-MZ(alphaRL(i,j))-MZ(alphaRR(i,j));
                %YawAccel(i,j)=YawMoment(i,j)./Izz(i,j)*180/pi;
                %w(i,j)=Ay(i,j)*g/(w(i,j)*R);
                w(i,j)=-sign(SI(i))*sqrt(abs(Ay(i,j).*g/R(i)));  
                 %{
                if Ay(i,j)>0
                    Q=0;
                elseif Ay(i,j)<=0 %&& j>1
                    Q=1;
                    %Ay(i,j)=Ay(i,j-1);
                    Ay(i,j)=0;
                    for Q=1:1
                        df(i,j)=1.93*(w(i,j)*R(i)).^2; %Down Force
                        dfR(i,j)=df(i,j)*car.copx/(1.53*2); %Down Force front
                        dfF(i,j)=df(i,j)*(1.53-car.copx)/(1.53*2); %Down Force rear

                        alphaFL(i,j)=((tan(VS(j))*(w(i,j)*R(i)))+(w(i,j)*car.a))./((w(i,j)*R(i))-w(i,j)*car.Tf/2)-SI(i); %slip angle front right en rad
                        %alphaFL(i,j)=((tan(VS(j))*R)+car.a)./(R-car.Tf/2)-SI(i); %slip angle front left en rad
                        if alphaFL(i,j)>sliplim;
                            alphaFL(i,j)=sliplim;
                        elseif alphaFL(i,j)<-sliplim;
                            alphaFL(i,j)=-sliplim;
                        end

                        alphaFR(i,j)=((tan(VS(j))*(w(i,j)*R(i)))+(w(i,j)*car.a))./((w(i,j)*R(i))+w(i,j)*car.Tf/2)-SI(i); %slip angle front right en rad
                        if alphaFR(i,j)>sliplim;
                            alphaFR(i,j)=sliplim;
                        elseif alphaFR(i,j)<-sliplim;
                            alphaFR(i,j)=-sliplim;
                        end

                        alphaRL(i,j)=((tan(VS(j))*(w(i,j)*R(i)))-(w(i,j)*car.b))./((w(i,j)*R(i))-w(i,j)*car.Tr/2); %slip angle rear left en rad           
                        if alphaRL(i,j)>sliplim;
                            alphaRL(i,j)=sliplim;
                        elseif alphaRL(i,j)<-sliplim;
                            alphaRL(i,j)=-sliplim;
                        end

                        alphaRR(i,j)=((tan(VS(j))*(w(i,j)*R(i)))-(w(i,j)*car.b))./((w(i,j)*R(i))+w(i,j)*car.Tr/2); %slip angle rear right en rad
                        if alphaRR(i,j)>sliplim;
                            alphaRR(i,j)=sliplim;
                        elseif alphaRR(i,j)<-sliplim;
                            alphaRR(i,j)=-sliplim;
                        end

                        %Weight transfer
                        WF(i,j)=Ay(i,j)*((g*car.weight/car.Tf)*((car.H*car.Kf/(car.Kf+car.Kr))+(car.b*car.Zrf/car.l))); %weight transfer front (La Ay es en g)
                        WR(i,j)=Ay(i,j)*((g*car.weight/car.Tr)*((car.H*car.Kr/(car.Kf+car.Kr))+(car.a*car.Zrr/car.l))); %weight transfer rear (La Ay es en g)

                        WFL(i,j)=WF(i,j);
                        WFR(i,j)=-WF(i,j);
                        WRL(i,j)=WR(i,j);
                        WRR(i,j)=-WR(i,j);

                        %Camber variation
                        rollangle(i,j)=Ay(i,j)*car.weight*g*car.H/(car.Kr+car.Kf);
                        gammaFL(i,j)=abs((gammaF0+0.55333*rollangle(i,j))*pi/180); %rollangle i camber en deg 
                        gammaFR(i,j)=abs((gammaF0-0.55333*rollangle(i,j))*pi/180); %rollangle i camber en deg 
                        gammaRL(i,j)=abs((gammaR0+0.55333*rollangle(i,j))*pi/180); %rollangle i camber en deg 
                        gammaRR(i,j)=abs((gammaR0-0.55333*rollangle(i,j))*pi/180); %rollangle i camber en deg 


                        %Front Left wheel
                        FzFL(i,j) = (g*car.weight*car.b/(car.l*2))+WFL(i,j)+dfF(i,j);
                        dfzFL(i,j)=(FzFL(i,j)-tire.Fz0)./tire.Fz0;
                        dpiFL=(car.PF-tire.P0)/tire.P0;
                        Shy0FL(i,j)=(tire.PHY1+tire.PHY2*dfzFL(i,j))*car.lambdaHy;
                        Svy0FL(i,j)=FzFL(i,j)*(tire.PVY1+tire.PVY2*dfzFL(i,j))*car.lambdaVy*car.lambdauy*z2;
                        SvygammaFL(i,j)=FzFL(i,j)*(tire.PVY3+tire.PVY4*dfzFL(i,j))*gammaFL(i,j)*car.lambdaKygamma*car.lambdauy*z2;
                        SvyFL(i,j)=Svy0FL(i,j)+SvygammaFL(i,j);
                        Kygamma0FL(i,j)=(tire.PKY6+tire.PKY7*dfzFL(i,j))*FzFL(i,j)*car.lambdaKygamma*(1+tire.PPY5*dpiFL);
                        Kyalpha0FL(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiFL)*sin(tire.PKY4*atan(FzFL(i,j)/((tire.PKY2*tire.Fz0*(1+tire.PPY2*dpiFL)))))*car.lambdaKyalpha;
                        KyalphaFL(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiFL)*sin(tire.PKY4*atan(FzFL(i,j)/((tire.PKY2+tire.PKY5*gammaFL(i,j)^2)*tire.Fz0*(1+tire.PPY2*dpiFL))))*(1-tire.PKY3*abs(gammaFL(i,j)))*car.lambdaKyalpha*z3;
                        ShygammaFL(i,j)=((Kygamma0FL(i,j)*gammaFL(i,j)-SvygammaFL(i,j))/KyalphaFL(i,j))*z0+z4-1;
                        ShyFL(i,j)=Shy0FL(i,j)+ShygammaFL(i,j);
                        alphayFL(i,j)=-(alphaFL(i,j)+ShyFL(i,j));
                        CyFL(i,j)=tire.PCY1*car.lambdaCy;
                        uyFL(i,j)=(tire.PDY1+tire.PDY2*dfzFL(i,j))*(1+tire.PPY3*dpiFL+tire.PPY4*dpiFL^2)*(1-tire.PDY3*gammaFL(i,j)^2)*car.lambdauy;
                        DyFL(i,j)=uyFL(i,j)*FzFL(i,j)*z2;
                        EyFL(i,j)=(tire.PEY1+tire.PEY2*dfzFL(i,j))*(1+tire.PEY5*gammaFL(i,j)^2-(tire.PEY3+tire.PEY4*gammaFL(i,j))*sign(alphayFL(i,j)))*car.lambdaEy;
                        ByFL(i,j)=KyalphaFL(i,j)/(CyFL(i,j)*DyFL(i,j));
                        FypFL(i,j)=DyFL(i,j)*sin(CyFL(i,j)*atan(ByFL(i,j)*alphayFL(i,j)-EyFL(i,j).*(ByFL(i,j)*alphayFL(i,j)-atan(ByFL(i,j)*alphayFL(i,j)))))+SvyFL(i,j);
                        %MF61Y:
                        Gxalpha=1;%combined slip weiht function
                        Svyk=0;%combined slip braking included
                        FyFL(i,j)=-Gxalpha*FypFL(i,j)+Svyk;


                        %Front Right wheel
                        FzFR(i,j) = (g*car.weight*car.b/(car.l*2))+WFR(i,j)+dfF(i,j);
                        dfzFR(i,j)=(FzFR(i,j)-tire.Fz0)./tire.Fz0;
                        dpiFR=(car.PF-tire.P0)/tire.P0;
                        Shy0FR(i,j)=(tire.PHY1+tire.PHY2*dfzFR(i,j))*car.lambdaHy;
                        Svy0FR(i,j)=FzFR(i,j)*(tire.PVY1+tire.PVY2*dfzFR(i,j))*car.lambdaVy*car.lambdauy*z2;
                        SvygammaFR(i,j)=FzFR(i,j)*(tire.PVY3+tire.PVY4*dfzFR(i,j))*gammaFR(i,j)*car.lambdaKygamma*car.lambdauy*z2;
                        SvyFR(i,j)=Svy0FR(i,j)+SvygammaFR(i,j);
                        Kygamma0FR(i,j)=(tire.PKY6+tire.PKY7*dfzFR(i,j))*FzFR(i,j)*car.lambdaKygamma*(1+tire.PPY5*dpiFR);
                        Kyalpha0FR(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiFR)*sin(tire.PKY4*atan(FzFR(i,j)/((tire.PKY2*tire.Fz0*(1+tire.PPY2*dpiFR)))))*car.lambdaKyalpha;
                        KyalphaFR(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiFR)*sin(tire.PKY4*atan(FzFR(i,j)/((tire.PKY2+tire.PKY5*gammaFR(i,j)^2)*tire.Fz0*(1+tire.PPY2*dpiFR))))*(1-tire.PKY3*abs(gammaFR(i,j)))*car.lambdaKyalpha*z3;
                        ShygammaFR(i,j)=((Kygamma0FR(i,j)*gammaFR(i,j)-SvygammaFR(i,j))/KyalphaFR(i,j))*z0+z4-1;
                        ShyFR(i,j)=Shy0FR(i,j)+ShygammaFR(i,j);
                        alphayFR(i,j)=alphaFR(i,j)+ShyFR(i,j);
                        CyFR(i,j)=tire.PCY1*car.lambdaCy;
                        uyFR(i,j)=(tire.PDY1+tire.PDY2*dfzFR(i,j))*(1+tire.PPY3*dpiFR+tire.PPY4*dpiFR^2)*(1-tire.PDY3*gammaFR(i,j)^2)*car.lambdauy;
                        DyFR(i,j)=uyFR(i,j)*FzFR(i,j)*z2;
                        EyFR(i,j)=(tire.PEY1+tire.PEY2*dfzFR(i,j))*(1+tire.PEY5*gammaFR(i,j)^2-(tire.PEY3+tire.PEY4*gammaFR(i,j))*sign(alphayFR(i,j)))*car.lambdaEy;
                        ByFR(i,j)=KyalphaFR(i,j)/(CyFR(i,j)*DyFR(i,j));
                        FypFR(i,j)=DyFR(i,j)*sin(CyFR(i,j)*atan(ByFR(i,j)*alphayFR(i,j)-EyFR(i,j).*(ByFR(i,j)*alphayFR(i,j)-atan(ByFR(i,j)*alphayFR(i,j)))))+SvyFR(i,j);
                        %MF61Y:
                        Gxalpha=1;%conbined slip weiht function
                        Svyk=0;%conbined slip braking included
                        FyFR(i,j)=Gxalpha*FypFR(i,j)+Svyk;


                        %Rear Left wheel
                        FzRL(i,j) = (g*car.weight*car.a/(car.l*2))+WRL(i,j)+dfR(i,j);
                        dfzRL(i,j)=(FzRL(i,j)-tire.Fz0)./tire.Fz0;
                        dpiRL=(car.PR-tire.P0)/tire.P0;
                        Shy0RL(i,j)=(tire.PHY1+tire.PHY2*dfzRL(i,j))*car.lambdaHy;
                        Svy0RL(i,j)=FzRL(i,j)*(tire.PVY1+tire.PVY2*dfzRL(i,j))*car.lambdaVy*car.lambdauy*z2;
                        SvygammaRL(i,j)=FzRL(i,j)*(tire.PVY3+tire.PVY4*dfzRL(i,j))*gammaRL(i,j)*car.lambdaKygamma*car.lambdauy*z2;
                        SvyRL(i,j)=Svy0RL(i,j)+SvygammaRL(i,j);
                        Kygamma0RL(i,j)=(tire.PKY6+tire.PKY7*dfzRL(i,j))*FzRL(i,j)*car.lambdaKygamma*(1+tire.PPY5*dpiRL);
                        Kyalpha0RL(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiRL)*sin(tire.PKY4*atan(FzRL(i,j)/((tire.PKY2*tire.Fz0*(1+tire.PPY2*dpiRL)))))*car.lambdaKyalpha;
                        KyalphaRL(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiRL)*sin(tire.PKY4*atan(FzRL(i,j)/((tire.PKY2+tire.PKY5*gammaRL(i,j)^2)*tire.Fz0*(1+tire.PPY2*dpiRL))))*(1-tire.PKY3*abs(gammaRL(i,j)))*car.lambdaKyalpha*z3;
                        ShygammaRL(i,j)=((Kygamma0RL(i,j)*gammaRL(i,j)-SvygammaRL(i,j))/KyalphaRL(i,j))*z0+z4-1;
                        ShyRL(i,j)=Shy0RL(i,j)+ShygammaRL(i,j);
                        alphayRL(i,j)=-(alphaRL(i,j)+ShyRL(i,j));
                        CyRL(i,j)=tire.PCY1*car.lambdaCy;
                        uyRL(i,j)=(tire.PDY1+tire.PDY2*dfzRL(i,j))*(1+tire.PPY3*dpiRL+tire.PPY4*dpiRL^2)*(1-tire.PDY3*gammaRL(i,j)^2)*car.lambdauy;
                        DyRL(i,j)=uyRL(i,j)*FzRL(i,j)*z2;
                        EyRL(i,j)=(tire.PEY1+tire.PEY2*dfzRL(i,j))*(1+tire.PEY5*gammaRL(i,j)^2-(tire.PEY3+tire.PEY4*gammaRL(i,j))*sign(alphayRL(i,j)))*car.lambdaEy;
                        ByRL(i,j)=KyalphaRL(i,j)/(CyRL(i,j)*DyRL(i,j));
                        FypRL(i,j)=DyRL(i,j)*sin(CyRL(i,j)*atan(ByRL(i,j)*alphayRL(i,j)-EyRL(i,j).*(ByRL(i,j)*alphayRL(i,j)-atan(ByRL(i,j)*alphayRL(i,j)))))+SvyRL(i,j);
                        %MF61Y:
                        Gxalpha=1;%conbined slip weiht function
                        Svyk=0;%conbined slip braking included
                        FyRL(i,j)=-Gxalpha*FypRL(i,j)+Svyk;


                        %Rear Right wheel
                        FzRR(i,j) =(g*car.weight*car.a/(car.l*2))+WRR(i,j)+dfR(i,j);
                        dfzRR(i,j)=(FzRR(i,j)-tire.Fz0)./tire.Fz0;
                        dpiRR=(car.PR-tire.P0)/tire.P0;
                        Shy0RR(i,j)=(tire.PHY1+tire.PHY2*dfzRR(i,j))*car.lambdaHy;
                        Svy0RR(i,j)=FzRR(i,j)*(tire.PVY1+tire.PVY2*dfzRR(i,j))*car.lambdaVy*car.lambdauy*z2;
                        SvygammaRR(i,j)=FzRR(i,j)*(tire.PVY3+tire.PVY4*dfzRR(i,j))*gammaRR(i,j)*car.lambdaKygamma*car.lambdauy*z2;
                        SvyRR(i,j)=Svy0RR(i,j)+SvygammaRR(i,j);
                        Kygamma0RR(i,j)=(tire.PKY6+tire.PKY7*dfzRR(i,j))*FzRR(i,j)*car.lambdaKygamma*(1+tire.PPY5*dpiRR);
                        Kyalpha0RR(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiRR)*sin(tire.PKY4*atan(FzRR(i,j)/((tire.PKY2*tire.Fz0*(1+tire.PPY2*dpiRR)))))*car.lambdaKyalpha;
                        KyalphaRR(i,j)=tire.PKY1*tire.Fz0*(1+tire.PPY1*dpiRR)*sin(tire.PKY4*atan(FzRR(i,j)/((tire.PKY2+tire.PKY5*gammaRR(i,j)^2)*tire.Fz0*(1+tire.PPY2*dpiRR))))*(1-tire.PKY3*abs(gammaRR(i,j)))*car.lambdaKyalpha*z3;
                        ShygammaRR(i,j)=((Kygamma0RR(i,j)*gammaRR(i,j)-SvygammaRR(i,j))/KyalphaRR(i,j))*z0+z4-1;
                        ShyRR(i,j)=Shy0RR(i,j)+ShygammaRR(i,j);
                        alphayRR(i,j)=alphaRR(i,j)+ShyRR(i,j);
                        CyRR(i,j)=tire.PCY1*car.lambdaCy;
                        uyRR(i,j)=(tire.PDY1+tire.PDY2*dfzRR(i,j))*(1+tire.PPY3*dpiRR+tire.PPY4*dpiRR^2)*(1-tire.PDY3*gammaRR(i,j)^2)*car.lambdauy;
                        DyRR(i,j)=uyRR(i,j)*FzRR(i,j)*z2;
                        EyRR(i,j)=(tire.PEY1+tire.PEY2*dfzRR(i,j))*(1+tire.PEY5*gammaRR(i,j)^2-(tire.PEY3+tire.PEY4*gammaRR(i,j))*sign(alphayRR(i,j)))*car.lambdaEy;
                        ByRR(i,j)=KyalphaRR(i,j)/(CyRR(i,j)*DyRR(i,j));
                        FypRR(i,j)=DyRR(i,j)*sin(CyRR(i,j)*atan(ByRR(i,j)*alphayRR(i,j)-EyRR(i,j).*(ByRR(i,j)*alphayRR(i,j)-atan(ByRR(i,j)*alphayRR(i,j)))))+SvyRR(i,j);
                        %MF61Y:
                        Gxalpha=1;%conbined slip weiht function
                        Svyk=0;%conbined slip braking included
                        FyRR(i,j)=Gxalpha*FypRR(i,j)+Svyk;
                        YawMoment(i,j)=(FyFL(i,j).*cos(SI(i))+FyFR(i,j).*cos(SI(i)))*car.a-(FyRR(i,j)+FyRL(i,j))*car.b +MZ(alphaFL(i,j))+MZ(alphaFR(i,j))+MZ(alphaRL(i,j))+MZ(alphaRR(i,j));
                    end
                    break
                end
                %}
                end
        end
    end
end

wmax=max(abs(w(:)))
Tskidpad= 2*pi/wmax
[M,N]=size(YawMoment);

%Plotting Yaw Moment versus Lateral Acceleration
figure
for i=1:N
    plot(Ay(:,i),YawMoment(:,i))
    hold on
end

for i=1:M
    plot(Ay(i,:),YawMoment(i,:))
    hold on
end
xlabel('Lateral accel [gs]')
ylabel('Yaw Moment [kg m]')
legendCell_VS = cellstr(num2str(VS*180/pi, 'VS=%-d'));
legendCell_SI = cellstr(num2str(SI*180/pi, 'SI=%-d'));
legend([legendCell_VS;legendCell_SI], 'NumColumns',2)


%{
figure
for i=1:N
    plot(Ay(:,i)/g,YawAccel(:,i))
    hold on
end
for i=1:M
    plot(Ay(i,:)/g,YawAccel(i,:))
    hold on
end
legendCell_VS = cellstr(num2str(VS', 'VS=%-d'));
legendCell_SI = cellstr(num2str(SI', 'SI=%-d'));
legend([legendCell_VS;legendCell_SI], 'NumColumns',2)
xlabel('Lateral accel [gs]')
ylabel('Yaw Accel [deg/s^2]')
%}
