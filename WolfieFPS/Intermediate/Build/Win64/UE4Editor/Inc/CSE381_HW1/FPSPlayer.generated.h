// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CSE381_HW1_FPSPlayer_generated_h
#error "FPSPlayer.generated.h already included, missing '#pragma once' in FPSPlayer.h"
#endif
#define CSE381_HW1_FPSPlayer_generated_h

#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_SPARSE_DATA
#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStopJump); \
	DECLARE_FUNCTION(execStartJump); \
	DECLARE_FUNCTION(execMoveRight); \
	DECLARE_FUNCTION(execMoveForward);


#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStopJump); \
	DECLARE_FUNCTION(execStartJump); \
	DECLARE_FUNCTION(execMoveRight); \
	DECLARE_FUNCTION(execMoveForward);


#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSPlayer(); \
	friend struct Z_Construct_UClass_AFPSPlayer_Statics; \
public: \
	DECLARE_CLASS(AFPSPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CSE381_HW1"), NO_API) \
	DECLARE_SERIALIZER(AFPSPlayer)


#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAFPSPlayer(); \
	friend struct Z_Construct_UClass_AFPSPlayer_Statics; \
public: \
	DECLARE_CLASS(AFPSPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CSE381_HW1"), NO_API) \
	DECLARE_SERIALIZER(AFPSPlayer)


#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSPlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSPlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSPlayer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSPlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSPlayer(AFPSPlayer&&); \
	NO_API AFPSPlayer(const AFPSPlayer&); \
public:


#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSPlayer(AFPSPlayer&&); \
	NO_API AFPSPlayer(const AFPSPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSPlayer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSPlayer)


#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_PRIVATE_PROPERTY_OFFSET
#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_11_PROLOG
#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_PRIVATE_PROPERTY_OFFSET \
	CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_SPARSE_DATA \
	CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_RPC_WRAPPERS \
	CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_INCLASS \
	CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_PRIVATE_PROPERTY_OFFSET \
	CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_SPARSE_DATA \
	CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_INCLASS_NO_PURE_DECLS \
	CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CSE381_HW1_API UClass* StaticClass<class AFPSPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CSE381_HW3_Source_CSE381_HW1_FPSPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
