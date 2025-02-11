; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p:16:16-i32:16-i64:16-f32:16-f64:16-a:8-n8:16-S16"
target triple = "msp430"

@Array = dso_local global [10 x [10 x i16]] zeroinitializer, align 2
@Seed = dso_local global i16 0, align 2
@Postotal = dso_local global i16 0, align 2
@Poscnt = dso_local global i16 0, align 2
@Negtotal = dso_local global i16 0, align 2
@Negcnt = dso_local global i16 0, align 2

; Function Attrs: noinline nounwind optnone
define dso_local i16 @main() #0 {
entry:
  %retval = alloca i16, align 2
  store i16 0, ptr %retval, align 2
  %call = call i16 @InitSeed()
  %call1 = call i16 @Test(ptr noundef @Array)
  ret i16 1
}

; Function Attrs: noinline nounwind optnone
define dso_local i16 @InitSeed() #0 {
entry:
  store i16 0, ptr @Seed, align 2
  ret i16 0
}

; Function Attrs: noinline nounwind optnone
define dso_local i16 @Test(ptr noundef %Array) #0 {
entry:
  %Array.addr = alloca ptr, align 2
  %StartTime = alloca i32, align 2
  %StopTime = alloca i32, align 2
  %TotalTime = alloca float, align 2
  store ptr %Array, ptr %Array.addr, align 2
  %0 = load ptr, ptr %Array.addr, align 2
  %call = call i16 @Initialize(ptr noundef %0)
  store i32 1000, ptr %StartTime, align 2
  %1 = load ptr, ptr %Array.addr, align 2
  call void @Sum(ptr noundef %1)
  store i32 1500, ptr %StopTime, align 2
  %2 = load i32, ptr %StopTime, align 2
  %3 = load i32, ptr %StartTime, align 2
  %sub = sub nsw i32 %2, %3
  %conv = sitofp i32 %sub to double
  %div = fdiv double %conv, 1.000000e+03
  %conv1 = fptrunc double %div to float
  store float %conv1, ptr %TotalTime, align 2
  ret i16 0
}

; Function Attrs: noinline nounwind optnone
define dso_local i16 @Initialize(ptr noundef %Array) #0 {
entry:
  %Array.addr = alloca ptr, align 2
  %OuterIndex = alloca i16, align 2
  %InnerIndex = alloca i16, align 2
  store ptr %Array, ptr %Array.addr, align 2
  store i16 0, ptr %OuterIndex, align 2
  br label %for.cond

for.cond:                                         ; preds = %for.inc5, %entry
  %0 = load i16, ptr %OuterIndex, align 2
  %cmp = icmp slt i16 %0, 10
  br i1 %cmp, label %for.body, label %for.end7

for.body:                                         ; preds = %for.cond
  store i16 0, ptr %InnerIndex, align 2
  br label %for.cond1

for.cond1:                                        ; preds = %for.inc, %for.body
  %1 = load i16, ptr %InnerIndex, align 2
  %cmp2 = icmp slt i16 %1, 10
  br i1 %cmp2, label %for.body3, label %for.end

for.body3:                                        ; preds = %for.cond1
  %call = call i16 @RandomInteger()
  %2 = load ptr, ptr %Array.addr, align 2
  %3 = load i16, ptr %OuterIndex, align 2
  %arrayidx = getelementptr inbounds [10 x i16], ptr %2, i16 %3
  %4 = load i16, ptr %InnerIndex, align 2
  %arrayidx4 = getelementptr inbounds [10 x i16], ptr %arrayidx, i16 0, i16 %4
  store i16 %call, ptr %arrayidx4, align 2
  br label %for.inc

for.inc:                                          ; preds = %for.body3
  %5 = load i16, ptr %InnerIndex, align 2
  %inc = add nsw i16 %5, 1
  store i16 %inc, ptr %InnerIndex, align 2
  br label %for.cond1, !llvm.loop !2

for.end:                                          ; preds = %for.cond1
  br label %for.inc5

for.inc5:                                         ; preds = %for.end
  %6 = load i16, ptr %OuterIndex, align 2
  %inc6 = add nsw i16 %6, 1
  store i16 %inc6, ptr %OuterIndex, align 2
  br label %for.cond, !llvm.loop !4

for.end7:                                         ; preds = %for.cond
  ret i16 0
}

; Function Attrs: noinline nounwind optnone
define dso_local void @Sum(ptr noundef %Array) #0 {
entry:
  %Array.addr = alloca ptr, align 2
  %Outer = alloca i16, align 2
  %Inner = alloca i16, align 2
  %Ptotal = alloca i16, align 2
  %Ntotal = alloca i16, align 2
  %Pcnt = alloca i16, align 2
  %Ncnt = alloca i16, align 2
  store ptr %Array, ptr %Array.addr, align 2
  store i16 0, ptr %Ptotal, align 2
  store i16 0, ptr %Ntotal, align 2
  store i16 0, ptr %Pcnt, align 2
  store i16 0, ptr %Ncnt, align 2
  store i16 0, ptr %Outer, align 2
  br label %for.cond

for.cond:                                         ; preds = %for.inc13, %entry
  %0 = load i16, ptr %Outer, align 2
  %cmp = icmp slt i16 %0, 10
  br i1 %cmp, label %for.body, label %for.end15

for.body:                                         ; preds = %for.cond
  store i16 0, ptr %Inner, align 2
  br label %for.cond1

for.cond1:                                        ; preds = %for.inc, %for.body
  %1 = load i16, ptr %Inner, align 2
  %cmp2 = icmp slt i16 %1, 10
  br i1 %cmp2, label %for.body3, label %for.end

for.body3:                                        ; preds = %for.cond1
  %2 = load ptr, ptr %Array.addr, align 2
  %3 = load i16, ptr %Outer, align 2
  %arrayidx = getelementptr inbounds [10 x i16], ptr %2, i16 %3
  %4 = load i16, ptr %Inner, align 2
  %arrayidx4 = getelementptr inbounds [10 x i16], ptr %arrayidx, i16 0, i16 %4
  %5 = load i16, ptr %arrayidx4, align 2
  %cmp5 = icmp slt i16 %5, 0
  br i1 %cmp5, label %if.then, label %if.else

if.then:                                          ; preds = %for.body3
  %6 = load ptr, ptr %Array.addr, align 2
  %7 = load i16, ptr %Outer, align 2
  %arrayidx6 = getelementptr inbounds [10 x i16], ptr %6, i16 %7
  %8 = load i16, ptr %Inner, align 2
  %arrayidx7 = getelementptr inbounds [10 x i16], ptr %arrayidx6, i16 0, i16 %8
  %9 = load i16, ptr %arrayidx7, align 2
  %10 = load i16, ptr %Ptotal, align 2
  %add = add nsw i16 %10, %9
  store i16 %add, ptr %Ptotal, align 2
  %11 = load i16, ptr %Pcnt, align 2
  %inc = add nsw i16 %11, 1
  store i16 %inc, ptr %Pcnt, align 2
  br label %if.end

if.else:                                          ; preds = %for.body3
  %12 = load ptr, ptr %Array.addr, align 2
  %13 = load i16, ptr %Outer, align 2
  %arrayidx8 = getelementptr inbounds [10 x i16], ptr %12, i16 %13
  %14 = load i16, ptr %Inner, align 2
  %arrayidx9 = getelementptr inbounds [10 x i16], ptr %arrayidx8, i16 0, i16 %14
  %15 = load i16, ptr %arrayidx9, align 2
  %16 = load i16, ptr %Ntotal, align 2
  %add10 = add nsw i16 %16, %15
  store i16 %add10, ptr %Ntotal, align 2
  %17 = load i16, ptr %Ncnt, align 2
  %inc11 = add nsw i16 %17, 1
  store i16 %inc11, ptr %Ncnt, align 2
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %18 = load i16, ptr %Inner, align 2
  %inc12 = add nsw i16 %18, 1
  store i16 %inc12, ptr %Inner, align 2
  br label %for.cond1, !llvm.loop !5

for.end:                                          ; preds = %for.cond1
  br label %for.inc13

for.inc13:                                        ; preds = %for.end
  %19 = load i16, ptr %Outer, align 2
  %inc14 = add nsw i16 %19, 1
  store i16 %inc14, ptr %Outer, align 2
  br label %for.cond, !llvm.loop !6

for.end15:                                        ; preds = %for.cond
  %20 = load i16, ptr %Ptotal, align 2
  store i16 %20, ptr @Postotal, align 2
  %21 = load i16, ptr %Pcnt, align 2
  store i16 %21, ptr @Poscnt, align 2
  %22 = load i16, ptr %Ntotal, align 2
  store i16 %22, ptr @Negtotal, align 2
  %23 = load i16, ptr %Ncnt, align 2
  store i16 %23, ptr @Negcnt, align 2
  ret void
}

; Function Attrs: noinline nounwind optnone
define dso_local i16 @RandomInteger() #0 {
entry:
  %0 = load i16, ptr @Seed, align 2
  %mul = mul nsw i16 %0, 133
  %add = add nsw i16 %mul, 81
  %rem = srem i16 %add, 8095
  store i16 %rem, ptr @Seed, align 2
  %1 = load i16, ptr @Seed, align 2
  ret i16 %1
}

attributes #0 = { noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 20.0.0git (git@github.com:OMA-NVM/llvm-project.git 777d7384b5b00264f0617c8d6f7146581c96ad05)"}
!1 = !{i32 1, !"wchar_size", i32 2}
!2 = distinct !{!2, !3}
!3 = !{!"llvm.loop.mustprogress"}
!4 = distinct !{!4, !3}
!5 = distinct !{!5, !3}
!6 = distinct !{!6, !3}
