; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p:16:16-i32:16-i64:16-f32:16-f64:16-a:8-n8:16-S16"
target triple = "msp430"

@WDTCTL = external dso_local global i16, align 2
@PM5CTL0 = external dso_local global i16, align 2
@PADIR_L = external dso_local global i8, align 1
@PAOUT_L = external dso_local global i8, align 1

; Function Attrs: noinline nounwind optnone
define dso_local i16 @main() #0 {
entry:
  %retval = alloca i16, align 2
  %i = alloca i16, align 2
  store i16 0, ptr %retval, align 2
  store volatile i16 23168, ptr @WDTCTL, align 2
  %0 = load volatile i16, ptr @PM5CTL0, align 2
  %and = and i16 %0, -2
  store volatile i16 %and, ptr @PM5CTL0, align 2
  %1 = load volatile i8, ptr @PADIR_L, align 1
  %conv = zext i8 %1 to i16
  %or = or i16 %conv, 1
  %conv1 = trunc i16 %or to i8
  store volatile i8 %conv1, ptr @PADIR_L, align 1
  br label %for.cond

for.cond:                                         ; preds = %do.end, %entry
  %2 = load volatile i8, ptr @PAOUT_L, align 1
  %conv2 = zext i8 %2 to i16
  %xor = xor i16 %conv2, 1
  %conv3 = trunc i16 %xor to i8
  store volatile i8 %conv3, ptr @PAOUT_L, align 1
  store volatile i16 -15536, ptr %i, align 2
  br label %do.body

do.body:                                          ; preds = %do.cond, %for.cond
  %3 = load volatile i16, ptr %i, align 2
  %dec = add i16 %3, -1
  store volatile i16 %dec, ptr %i, align 2
  br label %do.cond

do.cond:                                          ; preds = %do.body
  %4 = load volatile i16, ptr %i, align 2
  %cmp = icmp ne i16 %4, 0
  br i1 %cmp, label %do.body, label %do.end, !llvm.loop !2

do.end:                                           ; preds = %do.cond
  br label %for.cond
}

attributes #0 = { noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 20.0.0git (git@github.com:OMA-NVM/llvm-project.git 3ba2e5ce358289941f0bf2abdc6953002a4c190f)"}
!1 = !{i32 1, !"wchar_size", i32 2}
!2 = distinct !{!2, !3}
!3 = !{!"llvm.loop.mustprogress"}
