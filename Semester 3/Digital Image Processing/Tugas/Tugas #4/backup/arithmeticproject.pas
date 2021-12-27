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
    radioLoad: TRadioGroup;
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

var
  bmpR, bmpG, bmpB: array[0..1000, 0..1000] of byte;

procedure TformArithmetic.btnLoadClick(Sender: TObject);
var
  x, y: integer;
begin
  if radioLoad.ItemIndex = 0 then
  begin
    if openDialog.Execute then
    begin
      imgA.Picture.LoadFromFile(openDialog.FileName);
      for y:=0 to imgA.Height-1 do
      begin
        for x:=0 to imgA.Width-1 do
        begin
          bmpR[x,y] := Red(imgA.Canvas.Pixels[x,y]);
          bmpG[x,y] := Green(imgA.Canvas.Pixels[x,y]);
          bmpB[x,y] := Blue(imgA.Canvas.Pixels[x,y]);
        end;
      end;
    end;
  end
  else
  begin
    if openDialog.Execute then
    begin
      imgB.Picture.LoadFromFile(openDialog.FileName);
      for y:=0 to imgB.Height-1 do
      begin
        for x:=0 to imgB.Width-1 do
        begin
          bmpR[x,y] := Red(imgB.Canvas.Pixels[x,y]);
          bmpG[x,y] := Green(imgB.Canvas.Pixels[x,y]);
          bmpB[x,y] := Blue(imgB.Canvas.Pixels[x,y]);
        end;
      end;
    end;
  end;
end;

end.

