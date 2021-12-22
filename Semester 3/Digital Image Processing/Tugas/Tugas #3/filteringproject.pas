unit FilteringProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TFilteringForm }

  TFilteringForm = class(TForm)
    btnLoad: TButton;
    btnSave: TButton;
    btnCorrelation: TButton;
    btnConvolution: TButton;
    imgOriginal: TImage;
    imgMod: TImage;
    lblImageMod: TLabel;
    lblImageOri: TLabel;
    openDialog: TOpenDialog;
    radioGroupColor: TRadioGroup;
    radioGroupFilter: TRadioGroup;
    saveDialog: TSaveDialog;
  private

  public

  end;

var
  FilteringForm: TFilteringForm;

implementation

{$R *.lfm}

end.

