	.text
	.file	"cover.c"
	.globl	swi120                          ; -- Begin function swi120
	.p2align	1
	.type	swi120,@function
swi120:                                 ; @swi120
; %bb.0:                                ; %entry
	sub	#4, r1
	mov	r12, 2(r1)
	clr	0(r1)
	jmp	.LBB0_1
.LBB0_1:                                ; %for.cond
                                        ; =>This Inner Loop Header: Depth=1
	mov	0(r1), r12
	cmp	#120, r12
	jl	.LBB0_2
	br	#.LBB0_128
.LBB0_2:                                ; %for.cond
                                        ;   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_3
.LBB0_3:                                ; %for.body
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	0(r1), r12
	cmp	#120, r12
	jlo	.LBB0_4
	br	#.LBB0_125
.LBB0_4:                                ; %for.body
                                        ;   in Loop: Header=BB0_1 Depth=1
	add	r12, r12
	mov	.LJTI0_0(r12), r12
	br	r12
.LBB0_5:                                ; %sw.bb
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_6:                                ; %sw.bb1
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_7:                                ; %sw.bb3
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_8:                                ; %sw.bb5
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_9:                                ; %sw.bb7
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_10:                               ; %sw.bb9
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_11:                               ; %sw.bb11
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_12:                               ; %sw.bb13
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_13:                               ; %sw.bb15
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_14:                               ; %sw.bb17
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_15:                               ; %sw.bb19
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_16:                               ; %sw.bb21
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_17:                               ; %sw.bb23
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_18:                               ; %sw.bb25
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_19:                               ; %sw.bb27
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_20:                               ; %sw.bb29
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_21:                               ; %sw.bb31
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_22:                               ; %sw.bb33
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_23:                               ; %sw.bb35
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_24:                               ; %sw.bb37
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_25:                               ; %sw.bb39
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_26:                               ; %sw.bb41
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_27:                               ; %sw.bb43
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_28:                               ; %sw.bb45
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_29:                               ; %sw.bb47
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_30:                               ; %sw.bb49
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_31:                               ; %sw.bb51
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_32:                               ; %sw.bb53
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_33:                               ; %sw.bb55
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_34:                               ; %sw.bb57
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_35:                               ; %sw.bb59
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_36:                               ; %sw.bb61
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_37:                               ; %sw.bb63
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_38:                               ; %sw.bb65
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_39:                               ; %sw.bb67
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	br	#.LBB0_126
.LBB0_40:                               ; %sw.bb69
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_41:                               ; %sw.bb71
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_42:                               ; %sw.bb73
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_43:                               ; %sw.bb75
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_44:                               ; %sw.bb77
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_45:                               ; %sw.bb79
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_46:                               ; %sw.bb81
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_47:                               ; %sw.bb83
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_48:                               ; %sw.bb85
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_49:                               ; %sw.bb87
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_50:                               ; %sw.bb89
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_51:                               ; %sw.bb91
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_52:                               ; %sw.bb93
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_53:                               ; %sw.bb95
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_54:                               ; %sw.bb97
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_55:                               ; %sw.bb99
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_56:                               ; %sw.bb101
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_57:                               ; %sw.bb103
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_58:                               ; %sw.bb105
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_59:                               ; %sw.bb107
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_60:                               ; %sw.bb109
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_61:                               ; %sw.bb111
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_62:                               ; %sw.bb113
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_63:                               ; %sw.bb115
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_64:                               ; %sw.bb117
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_65:                               ; %sw.bb119
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_66:                               ; %sw.bb121
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_67:                               ; %sw.bb123
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_68:                               ; %sw.bb125
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_69:                               ; %sw.bb127
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_70:                               ; %sw.bb129
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_71:                               ; %sw.bb131
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_72:                               ; %sw.bb133
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_73:                               ; %sw.bb135
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_74:                               ; %sw.bb137
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_75:                               ; %sw.bb139
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_76:                               ; %sw.bb141
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_77:                               ; %sw.bb143
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_78:                               ; %sw.bb145
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_79:                               ; %sw.bb147
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_80:                               ; %sw.bb149
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_81:                               ; %sw.bb151
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_82:                               ; %sw.bb153
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_83:                               ; %sw.bb155
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_84:                               ; %sw.bb157
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_85:                               ; %sw.bb159
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_86:                               ; %sw.bb161
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_87:                               ; %sw.bb163
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_88:                               ; %sw.bb165
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_89:                               ; %sw.bb167
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_90:                               ; %sw.bb169
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_91:                               ; %sw.bb171
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_92:                               ; %sw.bb173
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_93:                               ; %sw.bb175
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_94:                               ; %sw.bb177
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_95:                               ; %sw.bb179
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_96:                               ; %sw.bb181
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_97:                               ; %sw.bb183
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_98:                               ; %sw.bb185
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_99:                               ; %sw.bb187
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_100:                              ; %sw.bb189
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_101:                              ; %sw.bb191
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_102:                              ; %sw.bb193
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_103:                              ; %sw.bb195
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_104:                              ; %sw.bb197
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_105:                              ; %sw.bb199
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_106:                              ; %sw.bb201
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_107:                              ; %sw.bb203
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_108:                              ; %sw.bb205
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_109:                              ; %sw.bb207
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_110:                              ; %sw.bb209
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_111:                              ; %sw.bb211
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_112:                              ; %sw.bb213
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_113:                              ; %sw.bb215
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_114:                              ; %sw.bb217
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_115:                              ; %sw.bb219
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_116:                              ; %sw.bb221
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_117:                              ; %sw.bb223
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_118:                              ; %sw.bb225
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_119:                              ; %sw.bb227
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_120:                              ; %sw.bb229
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_121:                              ; %sw.bb231
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_122:                              ; %sw.bb233
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_123:                              ; %sw.bb235
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_124:                              ; %sw.bb237
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_125:                              ; %sw.default
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	2(r1), r12
	add	#-1, r12
	mov	r12, 2(r1)
	jmp	.LBB0_126
.LBB0_126:                              ; %sw.epilog
                                        ;   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_127
.LBB0_127:                              ; %for.inc
                                        ;   in Loop: Header=BB0_1 Depth=1
	mov	0(r1), r12
	inc	r12
	mov	r12, 0(r1)
	br	#.LBB0_1
.LBB0_128:                              ; %for.end
	mov	2(r1), r12
	add	#4, r1
	ret
.Lfunc_end0:
	.size	swi120, .Lfunc_end0-swi120
	.section	.rodata,"a",@progbits
	.p2align	1, 0x0
.LJTI0_0:
	.short	.LBB0_5
	.short	.LBB0_6
	.short	.LBB0_7
	.short	.LBB0_8
	.short	.LBB0_9
	.short	.LBB0_10
	.short	.LBB0_11
	.short	.LBB0_12
	.short	.LBB0_13
	.short	.LBB0_14
	.short	.LBB0_15
	.short	.LBB0_16
	.short	.LBB0_17
	.short	.LBB0_18
	.short	.LBB0_19
	.short	.LBB0_20
	.short	.LBB0_21
	.short	.LBB0_22
	.short	.LBB0_23
	.short	.LBB0_24
	.short	.LBB0_25
	.short	.LBB0_26
	.short	.LBB0_27
	.short	.LBB0_28
	.short	.LBB0_29
	.short	.LBB0_30
	.short	.LBB0_31
	.short	.LBB0_32
	.short	.LBB0_33
	.short	.LBB0_34
	.short	.LBB0_35
	.short	.LBB0_36
	.short	.LBB0_37
	.short	.LBB0_38
	.short	.LBB0_39
	.short	.LBB0_40
	.short	.LBB0_41
	.short	.LBB0_42
	.short	.LBB0_43
	.short	.LBB0_44
	.short	.LBB0_45
	.short	.LBB0_46
	.short	.LBB0_47
	.short	.LBB0_48
	.short	.LBB0_49
	.short	.LBB0_50
	.short	.LBB0_51
	.short	.LBB0_52
	.short	.LBB0_53
	.short	.LBB0_54
	.short	.LBB0_55
	.short	.LBB0_56
	.short	.LBB0_57
	.short	.LBB0_58
	.short	.LBB0_59
	.short	.LBB0_60
	.short	.LBB0_61
	.short	.LBB0_62
	.short	.LBB0_63
	.short	.LBB0_64
	.short	.LBB0_65
	.short	.LBB0_66
	.short	.LBB0_67
	.short	.LBB0_68
	.short	.LBB0_69
	.short	.LBB0_70
	.short	.LBB0_71
	.short	.LBB0_72
	.short	.LBB0_73
	.short	.LBB0_74
	.short	.LBB0_75
	.short	.LBB0_76
	.short	.LBB0_77
	.short	.LBB0_78
	.short	.LBB0_79
	.short	.LBB0_80
	.short	.LBB0_81
	.short	.LBB0_82
	.short	.LBB0_83
	.short	.LBB0_84
	.short	.LBB0_85
	.short	.LBB0_86
	.short	.LBB0_87
	.short	.LBB0_88
	.short	.LBB0_89
	.short	.LBB0_90
	.short	.LBB0_91
	.short	.LBB0_92
	.short	.LBB0_93
	.short	.LBB0_94
	.short	.LBB0_95
	.short	.LBB0_96
	.short	.LBB0_97
	.short	.LBB0_98
	.short	.LBB0_99
	.short	.LBB0_100
	.short	.LBB0_101
	.short	.LBB0_102
	.short	.LBB0_103
	.short	.LBB0_104
	.short	.LBB0_105
	.short	.LBB0_106
	.short	.LBB0_107
	.short	.LBB0_108
	.short	.LBB0_109
	.short	.LBB0_110
	.short	.LBB0_111
	.short	.LBB0_112
	.short	.LBB0_113
	.short	.LBB0_114
	.short	.LBB0_115
	.short	.LBB0_116
	.short	.LBB0_117
	.short	.LBB0_118
	.short	.LBB0_119
	.short	.LBB0_120
	.short	.LBB0_121
	.short	.LBB0_122
	.short	.LBB0_123
	.short	.LBB0_124
                                        ; -- End function
	.text
	.globl	swi50                           ; -- Begin function swi50
	.p2align	1
	.type	swi50,@function
swi50:                                  ; @swi50
; %bb.0:                                ; %entry
	sub	#4, r1
	mov	r12, 2(r1)
	clr	0(r1)
	jmp	.LBB1_1
.LBB1_1:                                ; %for.cond
                                        ; =>This Inner Loop Header: Depth=1
	mov	0(r1), r12
	cmp	#50, r12
	jge	.LBB1_67
	jmp	.LBB1_2
.LBB1_2:                                ; %for.body
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	0(r1), r12
	cmp	#60, r12
	jhs	.LBB1_64
; %bb.3:                                ; %for.body
                                        ;   in Loop: Header=BB1_1 Depth=1
	add	r12, r12
	mov	.LJTI1_0(r12), r12
	br	r12
.LBB1_4:                                ; %sw.bb
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_5:                                ; %sw.bb1
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_6:                                ; %sw.bb3
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_7:                                ; %sw.bb5
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_8:                                ; %sw.bb7
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_9:                                ; %sw.bb9
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_10:                               ; %sw.bb11
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_11:                               ; %sw.bb13
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_12:                               ; %sw.bb15
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_13:                               ; %sw.bb17
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_14:                               ; %sw.bb19
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_15:                               ; %sw.bb21
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_16:                               ; %sw.bb23
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_17:                               ; %sw.bb25
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_18:                               ; %sw.bb27
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_19:                               ; %sw.bb29
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_20:                               ; %sw.bb31
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_21:                               ; %sw.bb33
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_22:                               ; %sw.bb35
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_23:                               ; %sw.bb37
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_24:                               ; %sw.bb39
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_25:                               ; %sw.bb41
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_26:                               ; %sw.bb43
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_27:                               ; %sw.bb45
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_28:                               ; %sw.bb47
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_29:                               ; %sw.bb49
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_30:                               ; %sw.bb51
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_31:                               ; %sw.bb53
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_32:                               ; %sw.bb55
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_33:                               ; %sw.bb57
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_34:                               ; %sw.bb59
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_35:                               ; %sw.bb61
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_36:                               ; %sw.bb63
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_37:                               ; %sw.bb65
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_38:                               ; %sw.bb67
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_39:                               ; %sw.bb69
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_40:                               ; %sw.bb71
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_41:                               ; %sw.bb73
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_42:                               ; %sw.bb75
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_43:                               ; %sw.bb77
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_44:                               ; %sw.bb79
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_45:                               ; %sw.bb81
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_46:                               ; %sw.bb83
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_47:                               ; %sw.bb85
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_48:                               ; %sw.bb87
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_49:                               ; %sw.bb89
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_50:                               ; %sw.bb91
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_51:                               ; %sw.bb93
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_52:                               ; %sw.bb95
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_53:                               ; %sw.bb97
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_54:                               ; %sw.bb99
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_55:                               ; %sw.bb101
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_56:                               ; %sw.bb103
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_57:                               ; %sw.bb105
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_58:                               ; %sw.bb107
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_59:                               ; %sw.bb109
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_60:                               ; %sw.bb111
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_61:                               ; %sw.bb113
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_62:                               ; %sw.bb115
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_63:                               ; %sw.bb117
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_64:                               ; %sw.default
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	2(r1), r12
	add	#-1, r12
	mov	r12, 2(r1)
	jmp	.LBB1_65
.LBB1_65:                               ; %sw.epilog
                                        ;   in Loop: Header=BB1_1 Depth=1
	jmp	.LBB1_66
.LBB1_66:                               ; %for.inc
                                        ;   in Loop: Header=BB1_1 Depth=1
	mov	0(r1), r12
	inc	r12
	mov	r12, 0(r1)
	jmp	.LBB1_1
.LBB1_67:                               ; %for.end
	mov	2(r1), r12
	add	#4, r1
	ret
.Lfunc_end1:
	.size	swi50, .Lfunc_end1-swi50
	.section	.rodata,"a",@progbits
	.p2align	1, 0x0
.LJTI1_0:
	.short	.LBB1_4
	.short	.LBB1_5
	.short	.LBB1_6
	.short	.LBB1_7
	.short	.LBB1_8
	.short	.LBB1_9
	.short	.LBB1_10
	.short	.LBB1_11
	.short	.LBB1_12
	.short	.LBB1_13
	.short	.LBB1_14
	.short	.LBB1_15
	.short	.LBB1_16
	.short	.LBB1_17
	.short	.LBB1_18
	.short	.LBB1_19
	.short	.LBB1_20
	.short	.LBB1_21
	.short	.LBB1_22
	.short	.LBB1_23
	.short	.LBB1_24
	.short	.LBB1_25
	.short	.LBB1_26
	.short	.LBB1_27
	.short	.LBB1_28
	.short	.LBB1_29
	.short	.LBB1_30
	.short	.LBB1_31
	.short	.LBB1_32
	.short	.LBB1_33
	.short	.LBB1_34
	.short	.LBB1_35
	.short	.LBB1_36
	.short	.LBB1_37
	.short	.LBB1_38
	.short	.LBB1_39
	.short	.LBB1_40
	.short	.LBB1_41
	.short	.LBB1_42
	.short	.LBB1_43
	.short	.LBB1_44
	.short	.LBB1_45
	.short	.LBB1_46
	.short	.LBB1_47
	.short	.LBB1_48
	.short	.LBB1_49
	.short	.LBB1_50
	.short	.LBB1_51
	.short	.LBB1_52
	.short	.LBB1_53
	.short	.LBB1_54
	.short	.LBB1_55
	.short	.LBB1_56
	.short	.LBB1_57
	.short	.LBB1_58
	.short	.LBB1_59
	.short	.LBB1_60
	.short	.LBB1_61
	.short	.LBB1_62
	.short	.LBB1_63
                                        ; -- End function
	.text
	.globl	swi10                           ; -- Begin function swi10
	.p2align	1
	.type	swi10,@function
swi10:                                  ; @swi10
; %bb.0:                                ; %entry
	sub	#4, r1
	mov	r12, 2(r1)
	clr	0(r1)
	jmp	.LBB2_1
.LBB2_1:                                ; %for.cond
                                        ; =>This Inner Loop Header: Depth=1
	mov	0(r1), r12
	cmp	#10, r12
	jge	.LBB2_17
	jmp	.LBB2_2
.LBB2_2:                                ; %for.body
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	0(r1), r12
	cmp	#10, r12
	jhs	.LBB2_14
; %bb.3:                                ; %for.body
                                        ;   in Loop: Header=BB2_1 Depth=1
	add	r12, r12
	mov	.LJTI2_0(r12), r12
	br	r12
.LBB2_4:                                ; %sw.bb
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_5:                                ; %sw.bb1
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_6:                                ; %sw.bb3
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_7:                                ; %sw.bb5
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_8:                                ; %sw.bb7
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_9:                                ; %sw.bb9
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_10:                               ; %sw.bb11
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_11:                               ; %sw.bb13
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_12:                               ; %sw.bb15
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_13:                               ; %sw.bb17
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	inc	r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_14:                               ; %sw.default
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	2(r1), r12
	add	#-1, r12
	mov	r12, 2(r1)
	jmp	.LBB2_15
.LBB2_15:                               ; %sw.epilog
                                        ;   in Loop: Header=BB2_1 Depth=1
	jmp	.LBB2_16
.LBB2_16:                               ; %for.inc
                                        ;   in Loop: Header=BB2_1 Depth=1
	mov	0(r1), r12
	inc	r12
	mov	r12, 0(r1)
	jmp	.LBB2_1
.LBB2_17:                               ; %for.end
	mov	2(r1), r12
	add	#4, r1
	ret
.Lfunc_end2:
	.size	swi10, .Lfunc_end2-swi10
	.section	.rodata,"a",@progbits
	.p2align	1, 0x0
.LJTI2_0:
	.short	.LBB2_4
	.short	.LBB2_5
	.short	.LBB2_6
	.short	.LBB2_7
	.short	.LBB2_8
	.short	.LBB2_9
	.short	.LBB2_10
	.short	.LBB2_11
	.short	.LBB2_12
	.short	.LBB2_13
                                        ; -- End function
	.text
	.globl	main                            ; -- Begin function main
	.p2align	1
	.type	main,@function
main:                                   ; @main
; %bb.0:                                ; %entry
	sub	#4, r1
	clr	2(r1)
	clr	0(r1)
	mov	0(r1), r12
	call	#swi10
	mov	r12, 0(r1)
	mov	0(r1), r12
	call	#swi50
	mov	r12, 0(r1)
	mov	0(r1), r12
	call	#swi120
	mov	r12, 0(r1)
	mov	0(r1), r12
	add	#4, r1
	ret
.Lfunc_end3:
	.size	main, .Lfunc_end3-main
                                        ; -- End function
	.ident	"clang version 20.0.0git"
	.section	".note.GNU-stack","",@progbits
