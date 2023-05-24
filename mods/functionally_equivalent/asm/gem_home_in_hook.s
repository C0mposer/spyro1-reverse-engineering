.set noreorder
#Replacing 0x8008013C
jal GemHomeIn     # JAL into our function
addiu $s0,$sp,0xe # Jump/Branch Delay instruction from compiler that we must have going into our function
j 0x80080218      # Once function returns from jal, jump to the neceserry spot in execution
nop               
