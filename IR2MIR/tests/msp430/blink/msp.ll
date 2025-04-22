; ModuleID = 'src/blink.c'
source_filename = "src/blink.c"
target datalayout = "e-m:e-p:16:16-i32:16-i64:16-f32:16-f64:16-a:8-n8:16-S16"
target triple = "msp430"

@WDTCTL = external dso_local global i16, align 2
@PM5CTL0 = external dso_local global i16, align 2
@PADIR_L = external dso_local global i8, align 1
@PAOUT_L = external dso_local global i8, align 1

; Function Attrs: nofree norecurse noreturn nounwind memory(readwrite, argmem: none)
define dso_local noundef i16 @main() local_unnamed_addr #0 !dbg !7 {
entry:
  %i = alloca i16, align 2, !DIAssignID !18
    #dbg_assign(i1 undef, !12, !DIExpression(), !18, ptr %i, !DIExpression(), !19)
  store volatile i16 23168, ptr @WDTCTL, align 2, !dbg !20, !tbaa !21
  %0 = load volatile i16, ptr @PM5CTL0, align 2, !dbg !25, !tbaa !21
  %and = and i16 %0, -2, !dbg !25
  store volatile i16 %and, ptr @PM5CTL0, align 2, !dbg !25, !tbaa !21
  %1 = load volatile i8, ptr @PADIR_L, align 1, !dbg !26, !tbaa !27
  %2 = or i8 %1, 1, !dbg !26
  store volatile i8 %2, ptr @PADIR_L, align 1, !dbg !26, !tbaa !27
  br label %for.cond, !dbg !28

for.cond:                                         ; preds = %do.end, %entry
  call void @llvm.lifetime.start.p0(i64 2, ptr nonnull %i), !dbg !29
  %3 = load volatile i8, ptr @PAOUT_L, align 1, !dbg !30, !tbaa !27
  %4 = xor i8 %3, 1, !dbg !30
  store volatile i8 %4, ptr @PAOUT_L, align 1, !dbg !30, !tbaa !27
  store volatile i16 -15536, ptr %i, align 2, !dbg !31, !tbaa !21, !DIAssignID !32
    #dbg_assign(i16 -15536, !12, !DIExpression(), !32, ptr %i, !DIExpression(), !19)
  br label %do.body, !dbg !33

do.body:                                          ; preds = %do.body, %for.cond
  %i.0.i.0.i.0.i.0. = load volatile i16, ptr %i, align 2, !dbg !34, !tbaa !21
  %dec = add i16 %i.0.i.0.i.0.i.0., -1, !dbg !34
  store volatile i16 %dec, ptr %i, align 2, !dbg !34, !tbaa !21, !DIAssignID !35
    #dbg_assign(i16 %dec, !12, !DIExpression(), !35, ptr %i, !DIExpression(), !19)
  %i.0.i.0.i.0.i.0.5 = load volatile i16, ptr %i, align 2, !dbg !36, !tbaa !21
  %cmp.not = icmp eq i16 %i.0.i.0.i.0.i.0.5, 0, !dbg !37
  br i1 %cmp.not, label %do.end, label %do.body, !dbg !38, !llvm.loop !39

do.end:                                           ; preds = %do.body
  call void @llvm.lifetime.end.p0(i64 2, ptr nonnull %i), !dbg !43
  br label %for.cond, !dbg !44, !llvm.loop !45
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #1

; Function Attrs: mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #1

attributes #0 = { nofree norecurse noreturn nounwind memory(readwrite, argmem: none) "no-trapping-math"="true" "stack-protector-buffer-size"="8" }
attributes #1 = { mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5}
!llvm.ident = !{!6}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 20.0.0git (git@github.com:OMA-NVM/llvm-project.git eec801ec2488509bd805f616670f025d9f4e5901)", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "src/blink.c", directory: "/Users/nilsholscher/workspaces/msp430_template")
!2 = !{i32 7, !"Dwarf Version", i32 4}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 2}
!5 = !{i32 7, !"debug-info-assignment-tracking", i1 true}
!6 = !{!"clang version 20.0.0git (git@github.com:OMA-NVM/llvm-project.git eec801ec2488509bd805f616670f025d9f4e5901)"}
!7 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 3, type: !8, scopeLine: 3, flags: DIFlagPrototyped | DIFlagAllCallsDescribed, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !0, retainedNodes: !11)
!8 = !DISubroutineType(types: !9)
!9 = !{!10}
!10 = !DIBasicType(name: "int", size: 16, encoding: DW_ATE_signed)
!11 = !{!12}
!12 = !DILocalVariable(name: "i", scope: !13, file: !1, line: 10, type: !16)
!13 = distinct !DILexicalBlock(scope: !14, file: !1, line: 9, column: 13)
!14 = distinct !DILexicalBlock(scope: !15, file: !1, line: 9, column: 5)
!15 = distinct !DILexicalBlock(scope: !7, file: !1, line: 9, column: 5)
!16 = !DIDerivedType(tag: DW_TAG_volatile_type, baseType: !17)
!17 = !DIBasicType(name: "unsigned int", size: 16, encoding: DW_ATE_unsigned)
!18 = distinct !DIAssignID()
!19 = !DILocation(line: 0, scope: !13)
!20 = !DILocation(line: 4, column: 12, scope: !7)
!21 = !{!22, !22, i64 0}
!22 = !{!"int", !23, i64 0}
!23 = !{!"omnipotent char", !24, i64 0}
!24 = !{!"Simple C/C++ TBAA"}
!25 = !DILocation(line: 5, column: 13, scope: !7)
!26 = !DILocation(line: 7, column: 11, scope: !7)
!27 = !{!23, !23, i64 0}
!28 = !DILocation(line: 9, column: 5, scope: !7)
!29 = !DILocation(line: 10, column: 9, scope: !13)
!30 = !DILocation(line: 12, column: 15, scope: !13)
!31 = !DILocation(line: 14, column: 11, scope: !13)
!32 = distinct !DIAssignID()
!33 = !DILocation(line: 15, column: 9, scope: !13)
!34 = !DILocation(line: 15, column: 13, scope: !13)
!35 = distinct !DIAssignID()
!36 = !DILocation(line: 16, column: 15, scope: !13)
!37 = !DILocation(line: 16, column: 17, scope: !13)
!38 = !DILocation(line: 15, column: 12, scope: !13)
!39 = distinct !{!39, !33, !40, !41, !42}
!40 = !DILocation(line: 16, column: 21, scope: !13)
!41 = !{!"llvm.loop.mustprogress"}
!42 = !{!"llvm.loop.unroll.disable"}
!43 = !DILocation(line: 17, column: 5, scope: !14)
!44 = !DILocation(line: 9, column: 5, scope: !14)
!45 = distinct !{!45, !46, !47, !42}
!46 = !DILocation(line: 9, column: 5, scope: !15)
!47 = !DILocation(line: 17, column: 5, scope: !15)
