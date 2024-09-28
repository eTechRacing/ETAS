% Initialize parameters automatically when the model gets loaded.
%
% In the File / Model properties dialog of the model, on the tab labeled
% Callbacks, set 'MyUserDriver_RTW_params' as the Model's pre-load function.
%
% An alternative way via the Matlab command line would be
%   set_param('MyUserDriver_RTW_RTW', 'PreLoadFcn', 'MyUserDriver_RTW_params');

disp('Executing MyUserDriver_RTW_params.m for parameter initialization');

kp = 0.5;
ki = 0.5;
kd = 0.0;
tPrev = 5.0;
vTrgt = 70.0;
TLPF = 0.5;
