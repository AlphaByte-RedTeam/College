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

  public

  end;

var
  FilteringForm: TFilteringForm;

implementation

{$R *.lfm}

end.

