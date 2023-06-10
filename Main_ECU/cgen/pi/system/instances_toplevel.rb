# Intermediate code, generated by INTECTRIO from template file:
# c:/program files (x86)/etas/intecrio4.7/build/common/tools/pi_core-4.6/templates/instances_toplevel.tpl
# DO NOT EDIT!

def output(file, str)
    file.write(str + "\n")
end

def make(node)
node_stack = []
file = File.new("#{node.node_table[:name]}_instances.h", "w")
output(file, "/*****************************************************************************")
output(file, " *")
output(file, " * #{node.node_table[:name]}_instances.h")
output(file, " *")
output(file, " * Part of INTECRIO Simulation Interface for generated software modules")
output(file, " *")
output(file, " * Generated by INTECRIO Project Integrator, do not edit!")
output(file, " *")
output(file, " * Copyright 2007 ETAS (ETAS GmbH)")
output(file, " *")
output(file, " *****************************************************************************/")
output(file, "/* Instance tree initialization */")
output(file, "extern ASDObject *initializeYukonModel(void);")
output(file, "/* Static delta T variable */")
output(file, "static real64 staticDT;")
output(file, "/* Function for grabbing the INTECRIO version */")
output(file, "const uint32 getIntecrioVersionNumber(void);")
output(file, "/* Functions for identifying the application which created this model */")
output(file, "enum { MODEL_TYPE_INTECRIO = 1 };")
output(file, "uint32 getBuildEnvironment(void);")
output(file, "uint32 getBuildEnvironmentVersion(void);")
output(file, "const char* getModelIdentificationString();")
output(file, "/* Definition of the class structure */")
output(file, "struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Class")
output(file, "{")
output(file, "    ASDObjectHeader objectHeader;")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "    struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj *#{node.node_table[:coder]}Top_#{node.node_table[:id]}_Ptr;")
    end
end
node = node_stack.pop()
output(file, "};")
output(file, "/* Definition of the class object structure */")
output(file, "struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj")
output(file, "{")
output(file, "    ASDObjectHeader objectHeader;")
output(file, "};")
file.close()
file = File.new("#{node.node_table[:name]}_instances.c", "w")
output(file, "/*****************************************************************************")
output(file, " *")
output(file, " * #{node.node_table[:name]}_instances.c")
output(file, " *")
output(file, " * Part of INTECRIO Simulation Interface for generated software modules")
output(file, " *")
output(file, " * Generated by INTECRIO Project Integrator, do not edit!")
output(file, " *")
output(file, " * Copyright 2007 ETAS (ETAS GmbH)")
output(file, " *")
output(file, " *****************************************************************************/")
output(file, "#include \"../a_basdef.h\"")
output(file, "#include \"#{node.node_table[:outdir]}/#{node.node_table[:name]}_instances.h\"")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "#include \"#{node.node_table[:outdir]}/#{node.node_table[:name]}_instances.h\"")
    end
end
node = node_stack.pop()
output(file, "/* Data structure for keeping the INTECRIO version (defines must be set) */")
output(file, "#ifdef INTECRIO_VERSION_NUMBER")
output(file, "static const uint32 intecrioVersionNumber = INTECRIO_VERSION_NUMBER;")
output(file, "const uint32 getIntecrioVersionNumber(void)")
output(file, "{")
output(file, "    return intecrioVersionNumber;")
output(file, "}")
output(file, "uint32 getBuildEnvironmentVersion(void)")
output(file, "{")
output(file, "    /* - The version number supplied by INTECRIO is AABBCCDD with")
output(file, "         AA: release, BB: update, CC: refresh, DD: patchlevel")
output(file, "       - This is bent into the appropriate shape (FFVVUURR) with")
output(file, "         FF: reserved, VV: major version, UU: update, RR: refresh */")
output(file, "    return (intecrioVersionNumber >> 8);")
output(file, "}")
output(file, "#else")
output(file, "#error \"define INTECRIO_VERSION_NUMBER must be set!\"")
output(file, "#endif")
output(file, "const char* modelIdentificationString = \"INTECRIO\";")
output(file, "const char* getModelIdentificationString()")
output(file, "{")
output(file, "    return modelIdentificationString;")
output(file, "}")
output(file, "uint32 getBuildEnvironment(void)")
output(file, "{")
output(file, "    return MODEL_TYPE_INTECRIO;")
output(file, "}")
output(file, "/* Program identifier (random number) */")
output(file, "/* uint32 programIdentifier = 0; */")
output(file, "/* Class initialization */")
output(file, "static void initClass_#{node.node_table[:coder]}Top_#{node.node_table[:id]}(struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Class *self)")
output(file, "{")
output(file, "    /* Intialize top level class variables */")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "    self->#{node.node_table[:coder]}Top_#{node.node_table[:id]}_Ptr = (struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj*)initModel_#{node.node_table[:coder]}Top_#{node.node_table[:id]}();")
    end
end
node = node_stack.pop()
output(file, "    return;")
output(file, "}")
output(file, "/* Definition of the class header */")
output(file, "static ASDClassHeader #{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassHeader =")
output(file, "    {0, 0, 0, #{node.node_table[:objlst].nil? ? 0 : node.node_table[:objlst].size}, (MethodList *)0, (MethodList *)0};")
output(file, "/* Definition and initialization of the class object */")
output(file, "static struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Class #{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassObj = {{1, {&#{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassHeader}, {0}}};")
output(file, "/* Object instantiation */")
output(file, "static struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj *initInstance_#{node.node_table[:coder]}Top_#{node.node_table[:id]}(void)")
output(file, "{")
output(file, "    struct #{node.node_table[:coder]}Top_#{node.node_table[:id]}_Obj *self;")
output(file, "    /* Object instantiation / implicit memory allocation */")
output(file, "    CREATE_OBJECT(self, #{node.node_table[:coder]}Top_#{node.node_table[:id]});")
output(file, "    return self;")
output(file, "}")
output(file, "/* Instance tree initialization */")
output(file, "ASDObject *initializeYukonModel (void)")
output(file, "{")
output(file, "    ASDObject *model;")
output(file, "    /* Top level class initialization */")
output(file, "    initClass_#{node.node_table[:coder]}Top_#{node.node_table[:id]}(&#{node.node_table[:coder]}Top_#{node.node_table[:id]}_ClassObj);")
output(file, "    /* Top Level object instantiation */")
output(file, "    model = (ASDObject *)initInstance_#{node.node_table[:coder]}Top_#{node.node_table[:id]}();")
output(file, "    return(model);")
output(file, "}")
output(file, "/* Initialization of dT variables */")
output(file, "void os_setDeltaT (void)")
output(file, "{")
output(file, "    staticDT = ((real64) (SYSTEM_TICK_DURATION * os_dT) / 1.0e9);")
output(file, "    /* Set dT for each module */")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "    setDeltaT_#{node.node_table[:id]}();")
    end
end
node = node_stack.pop()
output(file, "}")
output(file, "/* Accessor for staticDT */")
output(file, "uint32 getDeltaT (void)")
output(file, "{")
output(file, "    return (uint32)(staticDT * 1000000.0);")
output(file, "}")
output(file, "/* Generic accessor for system time in seconds */")
output(file, "real64 getSystemTimeS (void)")
output(file, "{")
output(file, "    return ((real64)(SYSTEM_TICK_DURATION * (SYSTEM_TIME_LOW +")
output(file, "            (uint64)(SYSTEM_TIME_HIGH * 4294967296.0)))) / 1000000000;")
output(file, "}")
file.close()
file = File.new("#{node.node_table[:name]}_instances.lst", "w")
output(file, "_PID_ ; 0")
node_stack.push(node)
unless(node.node_table[:objlst].nil?)
    node.node_table[:objlst].each() do
        |entry| 
        node = entry
output(file, "#{node.node_table[:id]} ; #{node.node_table[:name]} ; #{node.node_table[:coder]} ; 1001 0 ; #{node.node_table[:addr]}")
    end
end
node = node_stack.pop()
file.close()
# <EOF>

end
