% Nguyen Trung Tinh
% tinh.nguyenhayho@hcmut.edu.vn
% tinhhayho@gmail.com
% 
% yêu cầu UTF-8 để hiển thị đầy đủ kí tự
%
%
%
close all ;
clear all;
%%% thoi gian lay mau va thoi gian mo phong
Ts = 50e-6;
Tmophong = 1;
Iref1 = 2;
Iref2 = 3;
f_ref = 50; 
omega_Ref = 2*pi*50;
%% tao song sin tan so 50hz voi cac bien do khac nhau
time1 = (0:Ts:1);
y11    = Iref1.*sin(2*pi*50*time1);
y12    = Iref1.*sin(2*pi*50*time1 - 2*pi/3);
y13    = Iref1.*sin(2*pi*50*time1 + 2*pi/3);


time2 = ((1+Ts):Ts:2);
y21    = Iref2.*sin(2*pi*50*time2);
y22    = Iref2.*sin(2*pi*50*time2 - 2*pi/3);
y23    = Iref2.*sin(2*pi*50*time2 + 2*pi/3);


sinA = timetable(seconds([time1 time2]' ),[y11 y21]');
                
sinB = timetable(seconds([time1 time2]' ),[y12 y22]');
                 
sinC = timetable(seconds([time1 time2]' ),[y13 y23]');


%% thong so tai
R = 6; 
L = 30e-3;
C = 2200e-6;
Vdc = 100;
%% run simulink

sim('danhgia_chatluong.slx');

%% danh gia chat luong he thong
signal_out = ans.logsout.getElement('dongdien');
i_a_out = signal_out.Values.Data(:,1);
i_b_out = signal_out.Values.Data(:,2);
i_c_out = signal_out.Values.Data(:,3);


%% thong so phan tich fourier 

f = 0:1:length(i_a_out)-1;
fs = f/(length(i_a_out)*Ts);
phobiendo1 = abs((fft(i_a_out)*Ts));
subplot(3,1,1),
plot(fs, phobiendo1);

phobiendo2 = abs(fft(i_b_out)*Ts);
subplot(3,1,2),
plot(fs, phobiendo2);

phobiendo3 = abs(fft(i_c_out)*Ts);
subplot(3,1,3),
plot(fs, phobiendo3);

%% tinh ti so meo dang

Ia_coban = phobiendo1(51,1);
I_baccao = 0;
for i=2:100
    I_baccao =I_baccao + phobiendo1(i*50+1,1)^2;
end
THD1 = 100*sqrt(I_baccao)/(Ia_coban)

Ib_coban = phobiendo2(51,1);
I_baccao = 0;
for i=2:100
    I_baccao =I_baccao + phobiendo2(i*50+1,1)^2;
end
THD2 = 100*sqrt(I_baccao)/(Ib_coban)


Ic_coban = phobiendo3(51,1);
I_baccao = 0;
for i=2:100
    I_baccao =I_baccao + phobiendo3(i*50+1,1)^2;
end
THD3 = 100*sqrt(I_baccao)/(Ic_coban)

%% ve toa doc cuc

out2 =  ans.logsout.getElement('iampha');
out3 =  ans.logsout.getElement('ibeta');
out4 =  ans.logsout.getElement('iclarke');

iaref = out2.Values.Data(50:round(0.02/Ts)+50,1);
ibref = out3.Values.Data(50:round(0.02/Ts)+50,1);

iampre = out4.Values.Iampha.Data(50:round(0.02/Ts)+50,1);
ibepre = out4.Values.Ibeta.Data(50:round(0.02/Ts)+50,1);

[theta1, r1] = cart2pol(iaref, ibref);
[theta2, r2] = cart2pol(iampre, ibepre);
figure;
polarplot(theta1, r1);
hold on;
polarplot(theta2, r2);

%% vẽ dòng điện Ia* và Ia_p
t_aref = 1:1:length(iaref);
figure;
plot(t_aref, iaref,'--','LineWidth',3);
hold on;
plot(t_aref, iampre,'LineWidth',1);
legend(' I* dòng điện tham chiếu', 'Ialpha dòng điện thật');
title(' có bù trễ');













