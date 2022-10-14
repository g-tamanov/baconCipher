object FormMain: TFormMain
  Left = 0
  Top = 0
  BiDiMode = bdLeftToRight
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'BaconsCipher'
  ClientHeight = 300
  ClientWidth = 600
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  ParentBiDiMode = False
  Position = poScreenCenter
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelOutput: TLabel
    Left = 413
    Top = 135
    Width = 33
    Height = 13
    Caption = #1042#1099#1074#1086#1076
  end
  object LabelInput: TLabel
    Left = 117
    Top = 135
    Width = 25
    Height = 13
    Caption = #1042#1074#1086#1076
  end
  object ButtonDecrypted: TButton
    Left = 37
    Top = 199
    Width = 105
    Height = 25
    Caption = #1056#1072#1089#1096#1080#1092#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = ButtonDecryptedClick
  end
  object ButtonEncrypted: TButton
    Left = 37
    Top = 230
    Width = 105
    Height = 25
    Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1090#1100
    TabOrder = 1
    OnClick = ButtonEncryptedClick
  end
  object BaconsCipherMode: TRadioGroup
    Left = 286
    Top = 181
    Width = 268
    Height = 105
    Caption = #1042#1099#1073#1086#1088' '#1084#1077#1090#1086#1076#1072
    Color = clBtnFace
    ItemIndex = 0
    Items.Strings = (
      #1052#1077#1090#1086#1076' 1'
      #1052#1077#1090#1086#1076' 2'
      #1052#1077#1090#1086#1076' 3'
      #1052#1077#1090#1086#1076' 4')
    ParentBackground = False
    ParentColor = False
    TabOrder = 2
  end
  object LanguageMode: TRadioGroup
    Left = 181
    Top = 181
    Width = 90
    Height = 105
    BiDiMode = bdLeftToRight
    Caption = #1071#1079#1099#1082
    ItemIndex = 0
    Items.Strings = (
      'RU'
      'EN')
    ParentBiDiMode = False
    TabOrder = 3
  end
  object MemoInput: TMemo
    Left = 25
    Top = 40
    Width = 225
    Height = 89
    TabOrder = 4
  end
  object MemoOutput: TMemo
    Left = 317
    Top = 40
    Width = 225
    Height = 89
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object Clear: TButton
    Left = 392
    Top = 154
    Width = 75
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 6
    OnClick = ClearClick
  end
end
