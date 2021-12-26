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
    Load: TButton;
    Save: TButton;
    Correlation: TButton;
    Convolution: TButton;
    imgOri: TImage;
    imgMod: TImage;
    openDialog: TOpenDialog;
    radioFilterMode: TRadioGroup;
    radioColorMode: TRadioGroup;
    saveDialog: TSaveDialog;
  private

  public

  end;

var
  FilteringForm: TFilteringForm;

implementation

{$R *.lfm}

end.

