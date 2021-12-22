unit FilteringProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    btnLoad: TButton;
    btnSave: TButton;
    btnCorrelation: TButton;
    imgOriginal: TImage;
    imgMod: TImage;
    radioGroupColor: TRadioGroup;
    radioGroupFilter: TRadioGroup;
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

end.

