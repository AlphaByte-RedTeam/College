unit ArithmeticProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TformArithmetic }

  TformArithmetic = class(TForm)
    btnLoad: TButton;
    btnSave: TButton;
    btnProcess: TButton;
    imgA: TImage;
    imgB: TImage;
    imgMod: TImage;
    openDialog: TOpenDialog;
    RadioGroup1: TRadioGroup;
    saveDialog: TSaveDialog;
    procedure btnLoadClick(Sender: TObject);
  private

  public

  end;

var
  formArithmetic: TformArithmetic;

implementation

{$R *.lfm}

{ TformArithmetic }

uses
  windows, math;

end.

