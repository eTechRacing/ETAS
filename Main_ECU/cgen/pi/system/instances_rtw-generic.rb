# Intermediate code, generated by INTECTRIO from template file:
# c:/program files (x86)/etas/intecrio5.0/build/common/tools/pi_core-4.6/templates/instances_rtw-generic.tpl
# DO NOT EDIT!

def output(file, str)
    file.write(str + "\n")
end

def make(node)
node_stack = []
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
if(node.node_table[:active])
if(node.node_table[:coder]=='RTW')
file = File.new("#{node.node_table[:outdir]}/#{node.node_table[:name]}_instances.h", "w")
output(file, "/*****************************************************************************")
output(file, " *")
output(file, " * #{node.node_table[:name]}_instances.h")
output(file, " *")
output(file, " * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink")
output(file, " * Real-Time Workshop and Embedded Coder")
output(file, " *")
output(file, " * Generated by INTECRIO Project Integrator, do not edit!")
output(file, " *")
output(file, " * Copyright 2007 ETAS (ETAS GmbH)")
output(file, " *")
output(file, " *****************************************************************************/")
output(file, "/* Model initialization function prototype */")
output(file, "extern struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj *initModel_#{node.node_table[:coder]}Top_#{node.node_table[:id]}(void);")
output(file, "/* Level 1 class object declaration */")
output(file, "extern struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Class #{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassObj;")
output(file, "/* Level 1 class initialization function prototype */")
output(file, "extern void initClass_#{node.node_table[:coder]}Top_#{node.node_table[:id]}(struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Class *class);")
output(file, "/* Level 1 object instantiation function prototype */")
output(file, "extern struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj *initInstance_#{node.node_table[:coder]}Top_#{node.node_table[:id]}(void);")
output(file, "/* Function prototype for module specific setDeltaT() */")
output(file, "void setDeltaT_#{node.node_table[:id]}(void);")
node_stack.push(node)
unless(node.node_table[:cntrlst].nil?)
    node.node_table[:cntrlst].each() do
        |entry| 
        node = entry
output(file, "extern struct #{node.node_table[:coder]}_#{node.node_table[:id]}_Class #{node.node_table[:coder]}_#{node.node_table[:id]}_ClassObj;")
output(file, "extern void initClass_#{node.node_table[:coder]}_#{node.node_table[:id]}(struct #{node.node_table[:coder]}_#{node.node_table[:id]}_Class *self);")
output(file, "extern struct #{node.node_table[:coder]}_#{node.node_table[:id]}_Obj *initInstance_#{node.node_table[:coder]}_#{node.node_table[:id]}(void);")
    end
end
node = node_stack.pop()
output(file, "/* Definition of the class structure */")
output(file, "struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Class")
output(file, "{")
output(file, "    ASDObjectHeader objectHeader;")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "    #{node.node_table[:type]}Wrapper_Obj *#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr;")
    end
end
node = node_stack.pop()
node_stack.push(node)
unless(node.node_table[:cntrlst].nil?)
    node.node_table[:cntrlst].each() do
        |entry| 
        node = entry
output(file, "    struct #{node.node_table[:coder]}_#{node.node_table[:id]}_Obj *#{node.node_table[:coder]}_#{node.node_table[:id]}_Ptr;")
    end
end
node = node_stack.pop()
output(file, "};")
output(file, "/* Definition of the class object structure */")
output(file, "struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj")
output(file, "{")
output(file, "    ASDObjectHeader objectHeader;")
output(file, "};")
node_stack.push(node)
unless(node.node_table[:cntrlst].nil?)
    node.node_table[:cntrlst].each() do
        |entry| 
        node = entry
output(file, "struct #{node.node_table[:coder]}_#{node.node_table[:id]}_Class")
output(file, "{")
output(file, "    ASDObjectHeader objectHeader;")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "    #{node.node_table[:type]}Wrapper_Obj *#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr;")
    end
end
node = node_stack.pop()
output(file, "};")
output(file, "struct #{node.node_table[:coder]}_#{node.node_table[:id]}_Obj")
output(file, "{")
output(file, "    ASDObjectHeader objectHeader;")
output(file, "};")
    end
end
node = node_stack.pop()
file.close()
end
end
    end
end
node = node_stack.pop()
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
if(node.node_table[:active])
if(node.node_table[:coder]=='RTW')
file = File.new("#{node.node_table[:outdir]}/#{node.node_table[:name]}_instances.c", "w")
output(file, "/*****************************************************************************")
output(file, " *")
output(file, " * #{node.node_table[:name]}_instances.c")
output(file, " *")
output(file, " * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink")
output(file, " * Real-Time Workshop and Embedded Coder")
output(file, " *")
output(file, " * Generated by INTECRIO Project Integrator, do not edit!")
output(file, " *")
output(file, " * Copyright 2007 ETAS (ETAS GmbH)")
output(file, " *")
output(file, " *****************************************************************************/")
output(file, "  /* use void* as instance tree wrapper object pointer type */")
output(file, " #define Y_PRIMIT_VOID_PTR_FOR_ADDR")
output(file, "#define bool RTW_bool")
node_stack.push(node)
unless(node.node_table[:inclst].nil?)
    node.node_table[:inclst].each() do
        |entry| 
        node = entry
output(file, "#include \"#{node.node_table[:hdrfile]}\"")
    end
end
node = node_stack.pop()
output(file, "#undef bool")
output(file, "#undef false")
output(file, "#undef true")
output(file, "#include \"../a_basdef.h\"")
output(file, "#include \"#{node.node_table[:name]}_instances.h\"")
node_stack.push(node)
unless(node.node_table[:declst].nil?)
    node.node_table[:declst].each() do
        |entry| 
        node = entry
output(file, "extern #{node.node_table[:typeref]} #{node.node_table[:basedef]};")
    end
end
node = node_stack.pop()
output(file, "/* Initialization of Simulink model */")
output(file, "struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj *initModel_#{node.node_table[:coder]}Top_#{node.node_table[:id]}(void)")
output(file, "{")
output(file, "    struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj *model;")
output(file, "    /* Level 1 class initialization */")
node_stack.push(node)
unless(node.node_table[:cntrlst].nil?)
    node.node_table[:cntrlst].each() do
        |entry| 
        node = entry
output(file, "    initClass_#{node.node_table[:coder]}_#{node.node_table[:id]} (&#{node.node_table[:coder]}_#{node.node_table[:id]}_ClassObj);")
    end
end
node = node_stack.pop()
output(file, "    initClass_#{node.node_table[:coder]}Top_#{node.node_table[:id]} (&#{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassObj);")
output(file, "    /* Level 1 object instantiation */")
output(file, "    model = initInstance_#{node.node_table[:coder]}Top_#{node.node_table[:id]}();")
output(file, "    return(model);")
output(file, "}")
output(file, "/* Class initialization */")
output(file, "void initClass_#{node.node_table[:coder]}Top_#{node.node_table[:id]}(struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Class *self)")
output(file, "{")
output(file, "    /* Level 1 class variables */")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
if(node.node_table[:typeid]==1)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper((void*)&#{node.node_table[:var]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==2)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper((void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width]}, (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==3)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper((void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width_x]}, (uint32)#{node.node_table[:width_y]}, (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==4)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper((void*)&#{node.node_table[:var_ref1]}#{node.node_table[:ind_ref1]}, sizeof(#{node.node_table[:cdt_ref1]}), (void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width]}, (uint32)INTERPOLATE_LINEAR, (uint32)EXTRAPOLATE_CONST, (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==5)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper((void*)&#{node.node_table[:var_ref1]}#{node.node_table[:ind_ref1]}, sizeof(#{node.node_table[:cdt_ref1]}), (void*)&#{node.node_table[:var_ref2]}#{node.node_table[:ind_ref2]}, sizeof(#{node.node_table[:cdt_ref2]}), (void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width_ref1]}, (uint32)#{node.node_table[:width_ref2]}, (uint32)INTERPOLATE_LINEAR, (uint32)EXTRAPOLATE_CONST, (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==6)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper(&self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname_ref1]}_Ptr, (void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width]}, (uint32)INTERPOLATE_LINEAR, (uint32)EXTRAPOLATE_CONST, (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==7)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper(&self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname_ref1]}_Ptr, &self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname_ref2]}_Ptr, (void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width_ref1]}, (uint32)#{node.node_table[:width_ref2]}, (uint32)INTERPOLATE_LINEAR, (uint32)EXTRAPOLATE_CONST, (uint32)#{node.node_table[:kind]});")
end
    end
end
node = node_stack.pop()
node_stack.push(node)
unless(node.node_table[:cntrlst].nil?)
    node.node_table[:cntrlst].each() do
        |entry| 
        node = entry
output(file, "    self->#{node.node_table[:coder]}_#{node.node_table[:id]}_Ptr = initInstance_#{node.node_table[:coder]}_#{node.node_table[:id]}();")
    end
end
node = node_stack.pop()
output(file, "    return;")
output(file, "}")
node_stack.push(node)
unless(node.node_table[:cntrlst].nil?)
    node.node_table[:cntrlst].each() do
        |entry| 
        node = entry
output(file, "void initClass_#{node.node_table[:coder]}_#{node.node_table[:id]}(struct #{node.node_table[:coder]}_#{node.node_table[:id]}_Class *self)")
output(file, "{")
output(file, "    /* Level 2 class variables */")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
if(node.node_table[:typeid]==1)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper((void*)&#{node.node_table[:var]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==2)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper((void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width]}, (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==3)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper((void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width_x]}, (uint32)#{node.node_table[:width_y]}, (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==4)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper((void*)&#{node.node_table[:var_ref1]}#{node.node_table[:ind_ref1]}, sizeof(#{node.node_table[:cdt_ref1]}), (void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width]}, (uint32)INTERPOLATE_LINEAR, (uint32)EXTRAPOLATE_CONST, (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==5)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper((void*)&#{node.node_table[:var_ref1]}#{node.node_table[:ind_ref1]}, sizeof(#{node.node_table[:cdt_ref1]}), (void*)&#{node.node_table[:var_ref2]}#{node.node_table[:ind_ref2]}, sizeof(#{node.node_table[:cdt_ref2]}), (void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width_ref1]}, (uint32)#{node.node_table[:width_ref2]}, (uint32)INTERPOLATE_LINEAR, (uint32)EXTRAPOLATE_CONST, (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==6)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper(&self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname_ref1]}_Ptr, (void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width]}, (uint32)INTERPOLATE_LINEAR, (uint32)EXTRAPOLATE_CONST, (uint32)#{node.node_table[:kind]});")
elsif(node.node_table[:typeid]==7)
output(file, "    self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname]}_Ptr = initInstance_#{node.node_table[:type]}Wrapper(&self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname_ref1]}_Ptr, &self->#{node.node_table[:coder]}Wrapper_#{node.node_table[:cname_ref2]}_Ptr, (void*)&#{node.node_table[:var]}#{node.node_table[:ind]}, sizeof(#{node.node_table[:cdt]}), (uint32)#{node.node_table[:width_ref1]}, (uint32)#{node.node_table[:width_ref2]}, (uint32)INTERPOLATE_LINEAR, (uint32)EXTRAPOLATE_CONST, (uint32)#{node.node_table[:kind]});")
end
    end
end
node = node_stack.pop()
output(file, "}")
    end
end
node = node_stack.pop()
output(file, "static uint8 * _L1_getPid_#{node.node_table[:id]}(ASDObjectPtr self, uint8 *buffer)")
output(file, "{")
output(file, "    uint8 definedFlg = true;")
output(file, "    uint32 programIdentifier = 0;")
output(file, "    if(definedFlg == true)")
output(file, "    {")
output(file, "        addScalar(buffer, (uint8*)&programIdentifier, sizeof(programIdentifier));")
output(file, "    }")
output(file, "    addScalar(buffer, (uint8*)&definedFlg, sizeof(definedFlg));")
output(file, "    return(buffer);")
output(file, "}")
output(file, "/* Class method list */")
output(file, "static MethodList #{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassMethodList =")
output(file, "{")
output(file, "    (MethodPtr)_L1_getPid_#{node.node_table[:id]}")
output(file, "};")
output(file, "/* Definition of the class header */")
output(file, "static ASDClassHeader #{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassHeader =")
output(file, "    {0, 1, 0, #{node.node_table[:objlst].nil? ? 0 : node.node_table[:objlst].size} + #{node.node_table[:cntrlst].nil? ? 0 : node.node_table[:cntrlst].size}, (MethodList *)0, (MethodList *)&#{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassMethodList};")
output(file, "/* Definition and initialization of the class object */")
output(file, "struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Class #{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassObj = {{1, {&#{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassHeader}, {0}}")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "    ,NULL")
    end
end
node = node_stack.pop()
node_stack.push(node)
unless(node.node_table[:cntrlst].nil?)
    node.node_table[:cntrlst].each() do
        |entry| 
        node = entry
output(file, "    ,NULL")
    end
end
node = node_stack.pop()
output(file, "};")
node_stack.push(node)
unless(node.node_table[:cntrlst].nil?)
    node.node_table[:cntrlst].each() do
        |entry| 
        node = entry
output(file, "static ASDClassHeader #{node.node_table[:coder]}_#{node.node_table[:id]}_ClassHeader =")
output(file, "    {0, 0, 0, #{node.node_table[:objlst].nil? ? 0 : node.node_table[:objlst].size}, (MethodList *)0, (MethodList *) 0};")
output(file, "struct #{node.node_table[:coder]}_#{node.node_table[:id]}_Class #{node.node_table[:coder]}_#{node.node_table[:id]}_ClassObj = {{1, {&#{node.node_table[:coder]}_#{node.node_table[:id]}_ClassHeader}, {0}}")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "    ,NULL")
    end
end
node = node_stack.pop()
output(file, "};")
    end
end
node = node_stack.pop()
output(file, "/* Object instantiation */")
output(file, "struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj *initInstance_#{node.node_table[:coder]}Top_#{node.node_table[:id]}(void)")
output(file, "{")
output(file, "    struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj *self;")
output(file, "    /* Object instantiation / Implicit memory allocation */")
output(file, "    CREATE_OBJECT(self, #{node.node_table[:coder]}Top_#{node.node_table[:id]});")
output(file, "    return self;")
output(file, "}")
node_stack.push(node)
unless(node.node_table[:cntrlst].nil?)
    node.node_table[:cntrlst].each() do
        |entry| 
        node = entry
output(file, "struct #{node.node_table[:coder]}_#{node.node_table[:id]}_Obj *initInstance_#{node.node_table[:coder]}_#{node.node_table[:id]}(void)")
output(file, "{")
output(file, "    struct #{node.node_table[:coder]}_#{node.node_table[:id]}_Obj *self;")
output(file, "    /* Object instantiation / Implicit memory allocation */")
output(file, "    CREATE_OBJECT(self, #{node.node_table[:coder]}_#{node.node_table[:id]});")
output(file, "    return self;")
output(file, "}")
    end
end
node = node_stack.pop()
output(file, "void setDeltaT_#{node.node_table[:id]}(void)")
output(file, "{")
output(file, "}")
file.close()
end
end
    end
end
node = node_stack.pop()
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
if(node.node_table[:active])
if(node.node_table[:coder]=='RTW')
file = File.new("#{node.node_table[:outdir]}/#{node.node_table[:name]}_instances.lst", "w")
output(file, "_MID_ ; #{node.node_table[:id]}")
output(file, "_MNAME_ ; #{node.node_table[:name]}")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "#{node.node_table[:id]} ; #{node.node_table[:addr]} ; #{node.node_table[:kind]} ; #{node.node_table[:modpath]} ; #{node.node_table[:ecu_addr]}")
    end
end
node = node_stack.pop()
node_stack.push(node)
unless(node.node_table[:cntrlst].nil?)
    node.node_table[:cntrlst].each() do
        |entry| 
        node = entry
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "#{node.node_table[:id]} ; #{node.node_table[:parent_addr]} #{node.node_table[:addr]} ; #{node.node_table[:kind]} ; #{node.node_table[:modpath]} ; #{node.node_table[:ecu_addr]}")
    end
end
node = node_stack.pop()
    end
end
node = node_stack.pop()
file.close()
end
end
    end
end
node = node_stack.pop()
# <EOF>

end
