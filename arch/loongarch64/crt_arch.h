__asm__(
".section .sdata,\"aw\"\n"
".text\n"
".global " START "\n"
".type " START ",%function\n"
START ":\n"
"move $a5, $a0\n"
"move $a0, $sp\n"
".weak _DYNAMIC\n"
".hidden _DYNAMIC\n\t"
"la.pcrel $a1, _DYNAMIC\n\t"
"bstrins.d $sp, $zero, 3, 0\n\t"
"b " START "_c"
);
