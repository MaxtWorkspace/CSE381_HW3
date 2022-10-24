// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CSE381_HW1/Wolfie.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWolfie() {}
// Cross Module References
	CSE381_HW1_API UClass* Z_Construct_UClass_AWolfie_NoRegister();
	CSE381_HW1_API UClass* Z_Construct_UClass_AWolfie();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_CSE381_HW1();
// End Cross Module References
	void AWolfie::StaticRegisterNativesAWolfie()
	{
	}
	UClass* Z_Construct_UClass_AWolfie_NoRegister()
	{
		return AWolfie::StaticClass();
	}
	struct Z_Construct_UClass_AWolfie_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWolfie_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_CSE381_HW1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWolfie_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Wolfie.h" },
		{ "ModuleRelativePath", "Wolfie.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWolfie_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWolfie>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWolfie_Statics::ClassParams = {
		&AWolfie::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AWolfie_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWolfie_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWolfie()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWolfie_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWolfie, 1059617980);
	template<> CSE381_HW1_API UClass* StaticClass<AWolfie>()
	{
		return AWolfie::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWolfie(Z_Construct_UClass_AWolfie, &AWolfie::StaticClass, TEXT("/Script/CSE381_HW1"), TEXT("AWolfie"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWolfie);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
