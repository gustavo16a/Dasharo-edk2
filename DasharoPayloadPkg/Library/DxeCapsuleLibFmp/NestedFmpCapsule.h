#ifndef _NESTED_FMP_CAPSULE_H_
#define _NESTED_FMP_CAPSULE_H_

///
/// Define FMP Payload Header structure here so it is not public
///

#pragma pack(1)

typedef struct {
  UINT32    Signature;
  UINT32    HeaderSize;
  UINT32    FwVersion;
  UINT32    LowestSupportedVersion;
} FMP_PAYLOAD_HEADER;

#pragma pack()


/**
  Validate Nested Fmp capsules layout.

  Caution: This function may receive untrusted input.

  This function assumes the caller validated the capsule by using
  IsValidCapsuleHeader(), so that all fields in EFI_CAPSULE_HEADER are correct.
  The capsule buffer size is CapsuleHeader->CapsuleImageSize.

  This function validates the fields in EFI_FIRMWARE_MANAGEMENT_CAPSULE_HEADER
  and EFI_FIRMWARE_MANAGEMENT_CAPSULE_IMAGE_HEADER.

  This function checks if the payload is an FMP capsule

  @param[in, out] CapsuleHeader         Points to a capsule header.
                                        On input this parameter points to the top capsule header.
                                        On output this parameter points to the inner capsule header,
                                        if it exists and all operations succeeds.
  @param[out]     EmbeddedDriverCount   If the inner capsule exists, this parameter returns
                                        the EmbeddedDriverCount in the inner FMP capsule.

  @retval EFI_SUCCESS             The payload is an FMP capsule.
  @retval EFI_INVALID_PARAMETER   Top capsule is not a valid FMP capsule.
                                  Payload is not an FMP capsule or not valid FMP capsule.
                                  Signature is using an unexpected format.
  @retval EFI_UNSUPPORTED         The top capsule is contains EmbeddedDriver or multiple payloads.
  @retval EFI_SECURITY_VIOLATION  The inner capsule is not authentic.
  @retval Others                  Statuses returned by AuthenticateFmpImage
**/
EFI_STATUS
IsPayloadValidFmpCapsule (
  IN EFI_CAPSULE_HEADER  **CapsuleHeader,
  OUT UINT16             *EmbeddedDriverCount
  );


#endif // _NESTED_FMP_CAPSULE_H_