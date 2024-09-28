Simulink.Bus.cellToObject({

{
    'cm253D', {
       	{'x',	1,'double', -1, 'real', 'Sample'};
       	{'y',	1,'double', -1, 'real', 'Sample'};
       	{'z',	1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm253DRot', {
       	{'rx',	1,'double', -1, 'real', 'Sample'};
       	{'ry',	1,'double', -1, 'real', 'Sample'};
       	{'rz',	1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm253x3Mat', {
	{'r0c0',	1,'double', -1, 'real', 'Sample'};
	{'r0c1',	1,'double', -1, 'real', 'Sample'};
	{'r0c2',	1,'double', -1, 'real', 'Sample'};
	{'r1c0',	1,'double', -1, 'real', 'Sample'};
	{'r1c1',	1,'double', -1, 'real', 'Sample'};
	{'r1c2',	1,'double', -1, 'real', 'Sample'};
	{'r2c0',	1,'double', -1, 'real', 'Sample'};
	{'r2c1',	1,'double', -1, 'real', 'Sample'};
	{'r2c2',	1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm25AFIn', {
       	{'t_0',	1,'cm253D', -1, 'real', 'Sample'};
       	{'v_0',	1,'cm253D', -1, 'real', 'Sample'};
       	{'a_0',	1,'cm253D', -1, 'real', 'Sample'};
       	{'Tr2Fr0',	1,'cm253x3Mat', -1, 'real', 'Sample'};
       	{'r_zyx',	1,'cm253DRot', -1, 'real', 'Sample'};
       	{'rv_zyx',	1,'cm253DRot', -1, 'real', 'Sample'};
       	{'ra_zyx',	1,'cm253DRot', -1, 'real', 'Sample'};
       	{'omega_0',	1,'cm253DRot', -1, 'real', 'Sample'};
       	{'alpha_0',	1,'cm253DRot', -1, 'real', 'Sample'};
    }
}
{
    'cm25FrcCplIn', {
        {'qCalc',	1,'double', -1, 'real', 'Sample'};
        {'AF',	1,'cm25AFIn', -1, 'real', 'Sample'};
    }
}
{
    'cm25SKNCIn', {
	{'Frc2WC', 	1, 'cm253D', -1, 'real', 'Sample'};
	{'Trq2WC', 	1, 'cm253DRot', -1, 'real', 'Sample'};
       	{'FrcSpring',	1,'double', -1, 'real', 'Sample'};
       	{'FrcDamp',	1,'double', -1, 'real', 'Sample'};
       	{'FrcStabi',	1,'double', -1, 'real', 'Sample'};
       	{'FrcBuf',	1,'double', -1, 'real', 'Sample'};
       	{'qComp',	1,'double', -1, 'real', 'Sample'};
       	{'qpComp',	1,'double', -1, 'real', 'Sample'};
       	{'qppComp',	1,'double', -1, 'real', 'Sample'};
       	{'qSteer',	1,'double', -1, 'real', 'Sample'};
       	{'qpSteer',	1,'double', -1, 'real', 'Sample'};
       	{'qppSteer',	1,'double', -1, 'real', 'Sample'};
        {'FrcCpl',	1,'cm25FrcCplIn', -1, 'real', 'Sample'};
    }
}
{
    'cmSuspKnCIn', {
	{'MainIn', 	1, 'cm25SKNCIn', -1, 'real', 'Sample'};
	{'OppIn', 	1, 'cm25SKNCIn', -1, 'real', 'Sample'};
    }
}

{
    'cm25SKNCIX', {
       	{'ixtx',	1,'double', -1, 'real', 'Sample'};
       	{'ixty',	1,'double', -1, 'real', 'Sample'};
       	{'ixtz',	1,'double', -1, 'real', 'Sample'};
       	{'ixrx',	1,'double', -1, 'real', 'Sample'};
	{'ixry',	1,'double', -1, 'real', 'Sample'};
       	{'ixrz',	1,'double', -1, 'real', 'Sample'};
       	{'ixSpring',	1,'double', -1, 'real', 'Sample'};
       	{'ixDamp',	1,'double', -1, 'real', 'Sample'};
       	{'ixBuf',	1,'double', -1, 'real', 'Sample'};
       	{'ixStabi',	1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm25AFOut', {
       	{'Frc_1',	1,'cm253D', -1, 'real', 'Sample'};
       	{'Trq_1',	1,'cm253DRot', -1, 'real', 'Sample'};
       	{'Frc_Susp',	1,'cm253D', -1, 'real', 'Sample'};
       	{'Trq_Susp',	1,'cm253DRot', -1, 'real', 'Sample'};
    }
}
{
    'cm25WCOut', {
       	{'t_0',	1,'cm253D', -1, 'real', 'Sample'};
       	{'v_0',	1,'cm253D', -1, 'real', 'Sample'};
       	{'a_0',	1,'cm253D', -1, 'real', 'Sample'};
       	{'Tr2Fr0',	1,'cm253x3Mat', -1, 'real', 'Sample'};
       	{'omega_0',	1,'cm253DRot', -1, 'real', 'Sample'};
       	{'alpha_0',	1,'cm253DRot', -1, 'real', 'Sample'};
    }
}
{
    'cm25SKinFrcElems', {
       	{'xtof',	1,'cm253D', -1, 'real', 'Sample'};
       	{'TransAx',	1,'cm253D', -1, 'real', 'Sample'};
    }
}
{
    'cm25FrcCplOut', {
        {'AF',	1,'cm25AFOut', -1, 'real', 'Sample'};
        {'WC',	1,'cm25WCOut', -1, 'real', 'Sample'};
        {'Kin_Comp',	1,'cm25SKNCIX', -1, 'real', 'Sample'};
        {'Spring',	1,'cm25SKinFrcElems', -1, 'real', 'Sample'};
        {'Damper',	1,'cm25SKinFrcElems', -1, 'real', 'Sample'};
    }
}
{
    'cm25SKNCOut', {
	{'Kin', 	 1, 'cm25SKNCIX', -1, 'real', 'Sample'};
	{'Com', 	 1, 'cm25SKNCIX', -1, 'real', 'Sample'};
	{'dqComp', 	 1, 'cm25SKNCIX', -1, 'real', 'Sample'};
	{'dqSteer', 	 1, 'cm25SKNCIX', -1, 'real', 'Sample'};
	{'dqCompOpp', 	 1, 'cm25SKNCIX', -1, 'real', 'Sample'};
	{'FrcParasiticStiff', 1, 'double', -1, 'real', 'Sample'};
	{'FrcCpl', 	1, 'cm25FrcCplOut', -1, 'real', 'Sample'};
    }
}
{
    'cmSuspKnCOut', {
	{'MainOut', 	1, 'cm25SKNCOut', -1, 'real', 'Sample'};
	{'OppOut', 	1, 'cm25SKNCOut', -1, 'real', 'Sample'};
    }
}
});
