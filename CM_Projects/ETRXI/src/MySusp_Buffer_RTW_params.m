
% Initialize parameters automatically when the model gets loaded.
%
% In the File / Model properties dialog of the model, on the tab labeled
% Callbacks, set 'MySusp_Buffer_RTW_params' as the Model's pre-load function.
%
% An alternative way via the Matlab command line would be
%   set_param('MySusp_Buffer_RTW', 'PreLoadFcn', 'MySusp_Buffer_RTW_params');

disp('Executing MySusp_Buffer_RTW_params.m for parameter initialization');

Stiffness_Push = 50000;
Stiffness_Pull = 50000;
l0_Push = -0.055;
l0_Pull = 0.09;

