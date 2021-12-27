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
    procedure btnProcessClick(Sender: TObject);
    procedure btnSaveClick(Sender: TObject);
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
  bmpR, bmpG, bmpB, bmpGray, bmpBinary: array[0..1000, 0..1000] of byte;
  bmpR2, bmpG2, bmpB2, bmpGray2, bmpBinary2: array[0..1000, 0..1000] of byte;
  resR, resG, resB, resGray: array[0..1000, 0..1000] of byte;

procedure TformArithmetic.btnLoadClick(Sender: TObject);
var
  x, y, R, G, B, Gray: integer;
begin
  if radioLoad.ItemIndex = 0 then
  begin
    if openDialog.Execute then
    begin
      imgA.Picture.LoadFromFile(openDialog.FileName);

      imgB.Width := imgA.Width;
      imgB.Height := imgA.Height;
      imgB.Top := imgA.Top;
      imgB.Left := imgA.Left + 10 + imgA.Width;
      imgMod.Width := imgA.Width;
      imgMod.Height := imgA.Height;
      imgMod.Top := imgA.Top;
      imgMod.Left := imgA.Left + 2 * (10 + imgA.Width);

      for y:=0 to imgA.Height-1 do
      begin
        for x:=0 to imgA.Width-1 do
        begin
          R := GetRValue(imgA.Canvas.Pixels[x,y]);
          G := GetGValue(imgA.Canvas.Pixels[x,y]);
          B := GetBValue(imgA.Canvas.Pixels[x,y]);
          Gray := (R + G + B) div 3;
          bmpR[x,y] := R;
          bmpG[x,y] := G;
          bmpB[x,y] := B;
          bmpGray[x,y] := Gray;

          if Gray > 127 then
             bmpBinary[x,y] := 1
          else
            bmpBinary[x,y] := 0;
        end;
      end;
    end;
  end
  else
  begin
    if openDialog.Execute then
    begin
      imgB.Picture.LoadFromFile(openDialog.FileName);

      imgB.Width := imgA.Width;
      imgB.Height := imgA.Height;
      imgB.Top := imgA.Top;
      imgB.Left := imgA.Left + 10 + imgA.Width;
      imgMod.Width := imgA.Width;
      imgMod.Height := imgA.Height;
      imgMod.Top := imgA.Top;
      imgMod.Left := imgA.Left + 2 * (10 + imgA.Width);

      for y:=0 to imgB.Height-1 do
      begin
        for x:=0 to imgB.Width-1 do
        begin
          R := GetRValue(imgB.Canvas.Pixels[x,y]);
          G := GetGValue(imgB.Canvas.Pixels[x,y]);
          B := GetBValue(imgB.Canvas.Pixels[x,y]);
          Gray := (R + G + B) div 3;
          bmpR2[x,y] := R;
          bmpG2[x,y] := G;
          bmpB2[x,y] := B;
          bmpGray2[x,y] := Gray;
          if Gray > 127 then
             bmpBinary2[x,y] := 1
          else
            bmpBinary2[x,y] := 0;
        end;
      end;
    end;
  end;
end;

procedure TformArithmetic.btnProcessClick(Sender: TObject);
var
  x, y: integer;
begin
  for y:=0 to imgA.Height-1 do
  begin
    for x:=0 to imgA.Width-1 do
    begin
      resGray[x,y] := Round((bmpGray[x,y] + bmpGray2[x,y]) / 2);
      imgMod.Canvas.Pixels[x,y] := RGB(resGray[x,y], resGray[x,y], resGray[x,y]);
    end;
  end;
end;

procedure TformArithmetic.btnSaveClick(Sender: TObject);
begin
  if saveDialog.Execute then
     imgMod.Picture.SaveToFile(saveDialog.FileName);
end;

end.

