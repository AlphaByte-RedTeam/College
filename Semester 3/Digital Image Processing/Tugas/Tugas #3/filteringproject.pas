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
    radioGroupColor: TRadioGroup;
    radioGroupFilter: TRadioGroup;
  private

  public

  end;

var
  FilteringForm: TFilteringForm;

implementation

{$R *.lfm}

end.

