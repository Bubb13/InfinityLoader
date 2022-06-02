
python generate_bindings.py^
 -requestHeaderFile=./in/Baldur-v2.6.6.0.h^
 -requestTypesFile=./in/request_types.txt^
 -idaStructsFile=./in/Baldur-v2.6.6.0_ida_structs.txt^
 -fixupFile=in.request_fixup^
 -manualTypesFile=./in/request_manual_types.txt^
 > log_request.txt 2>&1
