// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CSE381_HW1/FPSModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSModeBase() {}
// Cross Module References
	CSE381_HW1_API UClass* Z_Construct_UClass_AFPSModeBase_NoRegister();
	CSE381_HW1_API UClass* Z_Construct_UClass_AFPSModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_CSE381_HW1();
// End Cross Module References
	void AFPSModeBase::StaticRegisterNativesAFPSModeBase()
	{
	}
	UClass* Z_Construct_UClass_AFPSModeBase_NoRegister()
	{
		return AFPSModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AFPSModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFPSModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_CSE381_HW1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FPSModeBase.h" },
		{ "ModuleRelativePath", "FPSModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFPSModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPSModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFPSModeBase_Statics::ClassParams = {
		&AFPSModeBase::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AFPSModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFPSModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFPSModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFPSModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFPSModeBase, 3939026445);
	template<> CSE381_HW1_API UClass* StaticClass<AFPSModeBase>()
	{
		return AFPSModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFPSModeBase(Z_Construct_UClass_AFPSModeBase, &AFPSModeBase::StaticClass, TEXT("/Script/CSE381_HW1"), TEXT("AFPSModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
