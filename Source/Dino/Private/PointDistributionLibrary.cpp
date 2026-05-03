#include "PointDistributionLibrary.h"

static bool IsFarEnough(
    const FVector& Candidate,
    const TArray<FVector>& Points,
    float MinDistance)
{
    float MinDistSq = MinDistance * MinDistance;

    for (const FVector& P : Points)
    {
        if (FVector::DistSquared(P, Candidate) < MinDistSq)
        {
            return false;
        }
    }

    return true;
}

TArray<FVector> UPointDistributionLibrary::GeneratePoissonLikePoints(
    FVector2D Min,
    FVector2D Max,
    float MinDistance,
    int32 TargetCount,
    int32 MaxAttempts,
    float Z,
    int32 Seed)
{
    TArray<FVector> Result;

    FRandomStream Stream(Seed);

    int32 Attempts = 0;

    while (Result.Num() < TargetCount && Attempts < MaxAttempts)
    {
        Attempts++;

        FVector Candidate;
        Candidate.X = Stream.FRandRange(Min.X, Max.X);
        Candidate.Y = Stream.FRandRange(Min.Y, Max.Y);
        Candidate.Z = Z;

        if (IsFarEnough(Candidate, Result, MinDistance))
        {
            Result.Add(Candidate);
        }
    }

    return Result;
}