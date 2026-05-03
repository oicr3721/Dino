#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PointDistributionLibrary.generated.h"

UCLASS()
class DINO_API UPointDistributionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "ProcGen")
    static TArray<FVector> GeneratePoissonLikePoints(
        FVector2D Min,
        FVector2D Max,
        float MinDistance,
        int32 TargetCount,
        int32 MaxAttempts,
        float Z,
        int32 Seed
    );
};