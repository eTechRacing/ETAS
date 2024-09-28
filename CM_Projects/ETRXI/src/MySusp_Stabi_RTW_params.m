
% Initialize parameters automatically when the model gets loaded.
%
% In the File / Model properties dialog of the model, on the tab labeled
% Callbacks, set 'MySusp_Stabi_RTW_params' as the Model's pre-load function.
%
% An alternative way via the Matlab command line would be
%   set_param('MySusp_Stabi_RTW', 'PreLoadFcn', 'MySusp_Stabi_RTW_params');

disp('Executing MySusp_Stabi_RTW_params.m for parameter initialization');

Stiffness = 15000;

