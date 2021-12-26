unit FilteringProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TFilteringForm }

  TFilteringForm = class(TForm)
    editKernel: TEdit;
    kernelSize: TLabel;
    btnLoad: TButton;
    btnSave: TButton;
    btnCorrelation: TButton;
    btnConvolution: TButton;
    imgOri: TImage;
    imgMod: TImage;
    openDialog: TOpenDialog;
    radioFilterMode: TRadioGroup;
    radioColorMode: TRadioGroup;
    saveDialog: TSaveDialog;
  private
    function constrain(val: integer): byte;

  public

  end;

var
  FilteringForm: TFilteringForm;

implementation

{$R *.lfm}

uses Windows;

var
  bmpR, bmpG, bmpB, bmpGray: array[0..1000, 0..1000] of byte;
  padR, padG, padB, padGray: array[0..1000, 0..1000] of double;
  kernel: array[0..100, 0..100] of double;
  __initWidth__, __initHeight__: integer;
  k, kHalf: integer;

{ TFilteringForm }

function TFilteringForm.constrain(val: integer): byte;
begin
  if val < 0 then
  begin
     constrain := 0;
  end
  else if val > 255 then
  begin
     constrain := 255;
  end
  else
      constrain := val;
end;

end.

