clear all
clc

g=9.81; %m/s^2

l = 1.53; %wheel base
a = 0.8; %Distance Front axis - COG 
b = l-a; %Distancia ruedas tras a cg
Tf = 1.25; %Trackwidth front
Tr = 1.15; %Trackwidth rear
weight = 320; %Pes amb pilot
Zrf=0.0964; %Roll center front m
Zrr=0.120; %Roll center rear m
Kf= 352.41; %roll stiffnes front maxima ajustabilidad +150 de lo que de el muelle
Kr= 296.70; %roll stiffnes rear maxima ajustabilidad +250 de lo que de el muelle
h= 0.28; %COG height m
H=h-((Zrr-Zrf)*a/l) % vertical height: roll axis and COG. Obtained wit similar triangles rules m
copx = 0.9; % center de pressure
lambdaHy=1;
lambdaVy=1;
lambdauy=0.59; %scaling factor
lambdaKygamma=1;
lambdaCy=1;
lambdaEy=1;
lambdaKyalpha=1;
lambdaKygamma=1;
PF=0.75; %Front pressure Bar
PR=0.75; %Rrear pressure Bar
gammaF0=-0.9; %Front Camber deg en negatiu
gammaR0=-0.9; %Rear Camber deg en negatiu

%Propietats del neumàtic
PCY1 = 1.5000; %shape factor (Afilar cantonades i estirar i atxatar)
PDY1 = 2.4360; %estirar o aixafar gràfica
PDY2 = -0.3628;
PDY3 = 10;
PEY1 = -0.0286; %afilar cantonades
PEY2 = 0.0113;
PEY3 = -0.2863; %en negatiu s'afila la dreta i en postiu l'esquerra
PEY4 = 32.0364;
PEY5 = -4.6821e+03;
PKY1 = -35.2758;
PKY2 = 1.7514; %rotar sobre el centre antihorari
PKY3 = 1.0000; 
PKY4 = 2.0000; 
PKY5 = -1.6874; 
PKY6 = 3.5692;
PKY7 = 1.9296;
PHY1 = 0.0043; %Desplaçar lateralment
PHY2 = 0; %Desplaçar lateralment
PVY1 = -0.0216; %pujar i baixar la grafica sencera
PVY2 = 0; %pujar i baixar la grafica sencera
PVY3 = 0.6492; %pujar i baixar la grafica sencera
PVY4 = 2.1293;
PPY1 = 0.2239; 
PPY2 = 0.9444;
PPY3 = -0.9607;
PPY4 = -2;
PPY5 = 0.0000;
Fz0 = 1080;
P0=0.97;
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

%Steering-Camber
C=@(S)0.0057*S^3+0.0278*S^2+0.0386*S; % S=steering input rad


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Inputs
V=90; %velocitat en X en km/h
deltadg=-15:1:15; %Steering angles en graus
SI=deltadg'.*pi/180; %Steering angle en rad
Betadg=-6:1:6; %Whole car slip angle en graus
VS=Betadg'.*pi/180; %Whole car slip angle rad
sliplim=17*pi/180; %Limit slip angle


%Izz=car.weight*(a^2+car.h^2); %Moment inercia
df=2.3*((V/3.6)^2) %Down Force
dfR=(df*copx)/l %dfR=df*copx/(1.53*2); Down Force front
dfF=df-dfR %dfF=df*(1.53-copx)/(1.53*2); Down Force rear
%Vy=(V./3.6)*tan(VS);
Wf=g*weight*b/l
Wr=g*weight*a/l


for i = 1:length(SI);
    for j = 1:length(VS);
        Vy(j)=(V/3.6).*VS(j); 
        w(i,j)=0;
        Ay(i,j)=0;
        for k=1:10     
            
            alphaFL(i,j)=((tan(VS(j))*(V/3.6))+(w(i,j)*a))./((V/3.6)-w(i,j)*Tf/2)-SI(i); %slip angle front left en rad
            if alphaFL(i,j)>sliplim;
                alphaFL(i,j)=sliplim;
            elseif alphaFL(i,j)<-sliplim;
                alphaFL(i,j)=-sliplim;
            end
            
            alphaFR(i,j)=((tan(VS(j))*(V/3.6))+(w(i,j)*a))./((V/3.6)+w(i,j)*Tf/2)-SI(i); %slip angle front right en rad
            if alphaFR(i,j)>sliplim;
                alphaFR(i,j)=sliplim;
            elseif alphaFR(i,j)<-sliplim;
                alphaFR(i,j)=-sliplim;
            end
            
            alphaRL(i,j)=((tan(VS(j))*(V/3.6))-(w(i,j)*b))./((V/3.6)-w(i,j)*Tr/2); %slip angle rear left en rad           
            if alphaRL(i,j)>sliplim;
                alphaRL(i,j)=sliplim;
            elseif alphaRL(i,j)<-sliplim;
                alphaRL(i,j)=-sliplim;
            end
            
            alphaRR(i,j)=((tan(VS(j))*(V/3.6))-(w(i,j)*b))./((V/3.6)+w(i,j)*Tr/2); %slip angle rear right en rad
            if alphaRR(i,j)>sliplim;
                alphaRR(i,j)=sliplim;
            elseif alphaRR(i,j)<-sliplim;
                alphaRR(i,j)=-sliplim;
            end
            
            %Weight transfer
            WF(i,j)=Ay(i,j)*((g*weight/Tf)*((H*Kf/(Kf+Kr))+(b*Zrf/l))); %weight transfer front (La Ay es en g)
            WR(i,j)=Ay(i,j)*((g*weight/Tr)*((H*Kr/(Kf+Kr))+(a*Zrr/l))); %weight transfer rear (La Ay es en g)
            
            WFL(i,j)=WF(i,j);
            WFR(i,j)=-WF(i,j);
            WRL(i,j)=WR(i,j);
            WRR(i,j)=-WR(i,j);
           
            %Camber variation with bodyroll increment
            rollangle(i,j)=Ay(i,j)*weight*g*H/(Kr+Kf);
            gammarFL(i,j)=abs((gammaF0+0.36842*rollangle(i,j))*pi/180); %rollangle i camber en rad 
            gammarFR(i,j)=abs((gammaF0-0.36842*rollangle(i,j))*pi/180); %rollangle i camber en rad
            gammarRL(i,j)=abs((gammaR0+0.36842*rollangle(i,j))*pi/180); %rollangle i camber en rad 
            gammarRR(i,j)=abs((gammaR0-0.36842*rollangle(i,j))*pi/180); %rollangle i camber en rad 
          
            %Camber variation with steering increment 
            gammasFL(i,j)=gammaF0*pi/180+C(SI(i)); % gammaFL rad
            gammasFR(i,j)=gammaF0*pi/180+C(SI(i)); %gammaFR rad
            
            %Total camber
            gammaFL(i,j)=gammarFL(i,j)+gammasFL(i,j);
            gammaFR(i,j)=gammarFR(i,j)+gammasFR(i,j);
            gammaRL(i,j)=gammarRL(i,j);
            gammaRR(i,j)=gammarRR(i,j);

            %Front Left wheel
            FzFL(i,j) = (Wf/2)+(WFL(i,j))+dfF/2;
            dfzFL(i,j)=(FzFL(i,j)-Fz0)./Fz0;
            dpiFL=(PF-P0)/P0;
            Shy0FL(i,j)=(PHY1+PHY2*dfzFL(i,j))*lambdaHy;
            Svy0FL(i,j)=FzFL(i,j)*(PVY1+PVY2*dfzFL(i,j))*lambdaVy*lambdauy*z2;
            SvygammaFL(i,j)=FzFL(i,j)*(PVY3+PVY4*dfzFL(i,j))*gammaFL(i,j)*lambdaKygamma*lambdauy*z2;%gammaFL rad
            SvyFL(i,j)=Svy0FL(i,j)+SvygammaFL(i,j);
            Kygamma0FL(i,j)=(PKY6+PKY7*dfzFL(i,j))*FzFL(i,j)*lambdaKygamma*(1+PPY5*dpiFL);
            Kyalpha0FL(i,j)=PKY1*Fz0*(1+PPY1*dpiFL)*sin(PKY4*atan(FzFL(i,j)/((PKY2*Fz0*(1+PPY2*dpiFL)))))*lambdaKyalpha;
            KyalphaFL(i,j)=PKY1*Fz0*(1+PPY1*dpiFL)*sin(PKY4*atan(FzFL(i,j)/((PKY2+PKY5*gammaFL(i,j)^2)*Fz0*(1+PPY2*dpiFL))))*(1-PKY3*abs(gammaFL(i,j)))*lambdaKyalpha*z3;%gammaFL rad
            ShygammaFL(i,j)=((Kygamma0FL(i,j)*gammaFL(i,j)-SvygammaFL(i,j))/KyalphaFL(i,j))*z0+z4-1;%gammaFL rad
            ShyFL(i,j)=Shy0FL(i,j)+ShygammaFL(i,j);
            alphayFL(i,j)=-(alphaFL(i,j)+ShyFL(i,j));
            CyFL(i,j)=PCY1*lambdaCy;
            uyFL(i,j)=(PDY1+PDY2*dfzFL(i,j))*(1+PPY3*dpiFL+PPY4*dpiFL^2)*(1-PDY3*gammaFL(i,j)^2)*lambdauy;%gammaFL rad
            DyFL(i,j)=uyFL(i,j)*FzFL(i,j)*z2;
            EyFL(i,j)=(PEY1+PEY2*dfzFL(i,j))*(1+PEY5*gammaFL(i,j)^2-(PEY3+PEY4*gammaFL(i,j))*sign(alphayFL(i,j)))*lambdaEy;%gammaFL rad
            ByFL(i,j)=KyalphaFL(i,j)/(CyFL(i,j)*DyFL(i,j));
            FypFL(i,j)=DyFL(i,j)*sin(CyFL(i,j)*atan(ByFL(i,j)*alphayFL(i,j)-EyFL(i,j).*(ByFL(i,j)*alphayFL(i,j)-atan(ByFL(i,j)*alphayFL(i,j)))))+SvyFL(i,j);
            %MF61Y:
            Gxalpha=1; %combined slip weiht function
            Svyk=0; %combined slip braking included
            FyFL(i,j)=-Gxalpha*FypFL(i,j)+Svyk; %From Magic Formula paper: Fy is perpendicular to wheel plane (not slip angle deviation)
            
            
            %Front Right wheel
            FzFR(i,j) = (Wf/2)+(WFR(i,j))+dfF/2;
            dfzFR(i,j)=(FzFR(i,j)-Fz0)./Fz0;
            dpiFR=(PF-P0)/P0;
            Shy0FR(i,j)=(PHY1+PHY2*dfzFR(i,j))*lambdaHy;
            Svy0FR(i,j)=FzFR(i,j)*(PVY1+PVY2*dfzFR(i,j))*lambdaVy*lambdauy*z2;
            SvygammaFR(i,j)=FzFR(i,j)*(PVY3+PVY4*dfzFR(i,j))*gammaFR(i,j)*lambdaKygamma*lambdauy*z2;
            SvyFR(i,j)=Svy0FR(i,j)+SvygammaFR(i,j);
            Kygamma0FR(i,j)=(PKY6+PKY7*dfzFR(i,j))*FzFR(i,j)*lambdaKygamma*(1+PPY5*dpiFR);
            Kyalpha0FR(i,j)=PKY1*Fz0*(1+PPY1*dpiFR)*sin(PKY4*atan(FzFR(i,j)/((PKY2*Fz0*(1+PPY2*dpiFR)))))*lambdaKyalpha;
            KyalphaFR(i,j)=PKY1*Fz0*(1+PPY1*dpiFR)*sin(PKY4*atan(FzFR(i,j)/((PKY2+PKY5*gammaFR(i,j)^2)*Fz0*(1+PPY2*dpiFR))))*(1-PKY3*abs(gammaFR(i,j)))*lambdaKyalpha*z3;
            ShygammaFR(i,j)=((Kygamma0FR(i,j)*gammaFR(i,j)-SvygammaFR(i,j))/KyalphaFR(i,j))*z0+z4-1;
            ShyFR(i,j)=Shy0FR(i,j)+ShygammaFR(i,j);
            alphayFR(i,j)=alphaFR(i,j)+ShyFR(i,j);
            CyFR(i,j)=PCY1*lambdaCy;
            uyFR(i,j)=(PDY1+PDY2*dfzFR(i,j))*(1+PPY3*dpiFR+PPY4*dpiFR^2)*(1-PDY3*gammaFR(i,j)^2)*lambdauy;
            DyFR(i,j)=uyFR(i,j)*FzFR(i,j)*z2;
            EyFR(i,j)=(PEY1+PEY2*dfzFR(i,j))*(1+PEY5*gammaFR(i,j)^2-(PEY3+PEY4*gammaFR(i,j))*sign(alphayFR(i,j)))*lambdaEy;
            ByFR(i,j)=KyalphaFR(i,j)/(CyFR(i,j)*DyFR(i,j));
            FypFR(i,j)=DyFR(i,j)*sin(CyFR(i,j)*atan(ByFR(i,j)*alphayFR(i,j)-EyFR(i,j).*(ByFR(i,j)*alphayFR(i,j)-atan(ByFR(i,j)*alphayFR(i,j)))))+SvyFR(i,j);
            %MF61Y:
            Gxalpha=1;%conbined slip weiht function
            Svyk=0;%conbined slip braking included
            FyFR(i,j)=Gxalpha*FypFR(i,j)+Svyk; %From Magic Formula paper: Fy is perpendicular to wheel plane (not slip angle deviation)
            
            
            %Rear Left wheel
            FzRL(i,j) = (Wr/2)+WRL(i,j)+dfR/2;
            dfzRL(i,j)=(FzRL(i,j)-Fz0)./Fz0;
            dpiRL=(PR-P0)/P0;
            Shy0RL(i,j)=(PHY1+PHY2*dfzRL(i,j))*lambdaHy;
            Svy0RL(i,j)=FzRL(i,j)*(PVY1+PVY2*dfzRL(i,j))*lambdaVy*lambdauy*z2;
            SvygammaRL(i,j)=FzRL(i,j)*(PVY3+PVY4*dfzRL(i,j))*gammaRL(i,j)*lambdaKygamma*lambdauy*z2;
            SvyRL(i,j)=Svy0RL(i,j)+SvygammaRL(i,j);
            Kygamma0RL(i,j)=(PKY6+PKY7*dfzRL(i,j))*FzRL(i,j)*lambdaKygamma*(1+PPY5*dpiRL);
            Kyalpha0RL(i,j)=PKY1*Fz0*(1+PPY1*dpiRL)*sin(PKY4*atan(FzRL(i,j)/((PKY2*Fz0*(1+PPY2*dpiRL)))))*lambdaKyalpha;
            KyalphaRL(i,j)=PKY1*Fz0*(1+PPY1*dpiRL)*sin(PKY4*atan(FzRL(i,j)/((PKY2+PKY5*gammaRL(i,j)^2)*Fz0*(1+PPY2*dpiRL))))*(1-PKY3*abs(gammaRL(i,j)))*lambdaKyalpha*z3;
            ShygammaRL(i,j)=((Kygamma0RL(i,j)*gammaRL(i,j)-SvygammaRL(i,j))/KyalphaRL(i,j))*z0+z4-1;
            ShyRL(i,j)=Shy0RL(i,j)+ShygammaRL(i,j);
            alphayRL(i,j)=-(alphaRL(i,j)+ShyRL(i,j));
            CyRL(i,j)=PCY1*lambdaCy;
            uyRL(i,j)=(PDY1+PDY2*dfzRL(i,j))*(1+PPY3*dpiRL+PPY4*dpiRL^2)*(1-PDY3*gammaRL(i,j)^2)*lambdauy;
            DyRL(i,j)=uyRL(i,j)*FzRL(i,j)*z2;
            EyRL(i,j)=(PEY1+PEY2*dfzRL(i,j))*(1+PEY5*gammaRL(i,j)^2-(PEY3+PEY4*gammaRL(i,j))*sign(alphayRL(i,j)))*lambdaEy;
            ByRL(i,j)=KyalphaRL(i,j)/(CyRL(i,j)*DyRL(i,j));
            FypRL(i,j)=DyRL(i,j)*sin(CyRL(i,j)*atan(ByRL(i,j)*alphayRL(i,j)-EyRL(i,j).*(ByRL(i,j)*alphayRL(i,j)-atan(ByRL(i,j)*alphayRL(i,j)))))+SvyRL(i,j);
            %MF61Y:
            Gxalpha=1;%conbined slip weiht function
            Svyk=0;%conbined slip braking included
            FyRL(i,j)=-Gxalpha*FypRL(i,j)+Svyk; %From Magic Formula paper: Fy is perpendicular to wheel plane (not slip angle deviation)
            
            
            %Rear Right wheel
            FzRR(i,j) =(Wr/2)+(WRR(i,j))+dfR/2;
            dfzRR(i,j)=(FzRR(i,j)-Fz0)./Fz0;
            dpiRR=(PR-P0)/P0;
            Shy0RR(i,j)=(PHY1+PHY2*dfzRR(i,j))*lambdaHy;
            Svy0RR(i,j)=FzRR(i,j)*(PVY1+PVY2*dfzRR(i,j))*lambdaVy*lambdauy*z2;
            SvygammaRR(i,j)=FzRR(i,j)*(PVY3+PVY4*dfzRR(i,j))*gammaRR(i,j)*lambdaKygamma*lambdauy*z2;
            SvyRR(i,j)=Svy0RR(i,j)+SvygammaRR(i,j);
            Kygamma0RR(i,j)=(PKY6+PKY7*dfzRR(i,j))*FzRR(i,j)*lambdaKygamma*(1+PPY5*dpiRR);
            Kyalpha0RR(i,j)=PKY1*Fz0*(1+PPY1*dpiRR)*sin(PKY4*atan(FzRR(i,j)/((PKY2*Fz0*(1+PPY2*dpiRR)))))*lambdaKyalpha;
            KyalphaRR(i,j)=PKY1*Fz0*(1+PPY1*dpiRR)*sin(PKY4*atan(FzRR(i,j)/((PKY2+PKY5*gammaRR(i,j)^2)*Fz0*(1+PPY2*dpiRR))))*(1-PKY3*abs(gammaRR(i,j)))*lambdaKyalpha*z3;
            ShygammaRR(i,j)=((Kygamma0RR(i,j)*gammaRR(i,j)-SvygammaRR(i,j))/KyalphaRR(i,j))*z0+z4-1;
            ShyRR(i,j)=Shy0RR(i,j)+ShygammaRR(i,j);
            alphayRR(i,j)=alphaRR(i,j)+ShyRR(i,j);
            CyRR(i,j)=PCY1*lambdaCy;
            uyRR(i,j)=(PDY1+PDY2*dfzRR(i,j))*(1+PPY3*dpiRR+PPY4*dpiRR^2)*(1-PDY3*gammaRR(i,j)^2)*lambdauy;
            DyRR(i,j)=uyRR(i,j)*FzRR(i,j)*z2;
            EyRR(i,j)=(PEY1+PEY2*dfzRR(i,j))*(PEY5*gammaRR(i,j)^2-(PEY3+PEY4*gammaRR(i,j))*sign(alphayRR(i,j)))*lambdaEy;
            ByRR(i,j)=KyalphaRR(i,j)/(CyRR(i,j)*DyRR(i,j));
            FypRR(i,j)=DyRR(i,j)*sin(CyRR(i,j)*atan(ByRR(i,j)*alphayRR(i,j)-EyRR(i,j).*(ByRR(i,j)*alphayRR(i,j)-atan(ByRR(i,j)*alphayRR(i,j)))))+SvyRR(i,j);
            %MF61Y:
            Gxalpha=1;%conbined slip weight function
            Svyk=0;%conbined slip braking included
            FyRR(i,j)=Gxalpha*FypRR(i,j)+Svyk; %From Magic Formula paper: Fy is perpendicular to wheel plane (not slip angle deviation)
            
            
            Izz(i,j)=(a/l)*(FzFL(i,j)+FzFR(i,j))*a^2+(b/l)*(FzRR(i,j)+FzRL(i,j))*b^2;
            Ay(i,j)=(FyFL(i,j)*(cos(SI(i)))+FyFR(i,j)*(cos(SI(i)))+(FyRR(i,j)+FyRL(i,j)))/(weight*g); %Acceleracio lateral o centripeta en g
            %Ay(i,j)=(FyFL(i,j)*(cos(SI(i)-alphaFL(i,j)))+FyFR(i,j)*(cos(SI(i)-alphaFR(i,j)))+(FyRR(i,j)+FyRL(i,j)))/(weight*g); %Acceleracio lateral o centripeta
            YawMoment(i,j)=(FyFL(i,j).*cos(SI(i))+FyFR(i,j).*cos(SI(i)))*a-(FyRR(i,j)+FyRL(i,j))*b+MZ(alphaFL(i,j))+MZ(alphaFR(i,j))+MZ(alphaRL(i,j))+MZ(alphaRR(i,j));
            %YawMoment(i,j)=(FyFL(i,j).*cos(SI(i)-alphaFL(i,j))+FyFR(i,j).*cos(SI(i)-alphaFL(i,j)))*a-(FyRR(i,j)+FyRL(i,j))*b-MZ(alphaFL(i,j))-MZ(alphaFR(i,j))-MZ(alphaRL(i,j))-MZ(alphaRR(i,j));
            YawAccel(i,j)=YawMoment(i,j)./Izz(i,j)*180/pi;
            w(i,j)=Ay(i,j)*g/(V/3.6);
            %R=Ay(i,j)./(w^2);
        end
    end
end
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
% legendCell_VS = cellstr(num2str(VS', 'VS=%-d'));
% legendCell_SI = cellstr(num2str(SI', 'SI=%-d'));
% legend([legendCell_VS;legendCell_SI], 'NumColumns',2)
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


