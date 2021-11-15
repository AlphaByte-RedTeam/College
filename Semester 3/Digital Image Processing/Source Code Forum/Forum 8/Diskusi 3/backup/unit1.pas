unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  ComCtrls;

type

  { TVisibleWatermark }

  TVisibleWatermark = class(TForm)
    btnLoadA: TButton;
    btnLoadB: TButton;
    btnSave: TButton;
    btnBlend: TButton;
    imgResult: TImage;
    imgBlend: TImage;
    imgA: TImage;
    OpenDialog: TOpenDialog;
    SaveDialog: TSaveDialog;
    textParameter: TStaticText;
    textImageA: TStaticText;
    textImageBlend: TStaticText;
    textImageResult: TStaticText;
    tBarParameter: TTrackBar;
    procedure btnBlendClick(Sender: TObject);
    procedure btnLoadAClick(Sender: TObject);
    procedure btnLoadBClick(Sender: TObject);
    procedure btnSaveClick(Sender: TObject);
  private

  public

  end;

var
  VisibleWatermark: TVisibleWatermark;

implementation

{$R *.lfm}

{ TVisibleWatermark }

uses Windows;

var
  bmpR, bmpG, bmpB: array[0..1000, 0..1000] of byte;
  imgA, imgBlend, imgResult: array[0..1000, 0..1000] of byte;

procedure TVisibleWatermark.btnLoadAClick(Sender: TObject);
var
  x, y: integer;
begin
  if OpenDialog.Execute then
  begin
    imgA.Picture.LoadFromFile(OpenDialog.FileName);
    for y:=0 to imgA.Height-1 do
    begin
      for x:=0 to imgA.Width-1 do
      begin
        bmpR[x, y] := getRValue(imgA.Canvas.Pixels[x, y]);
        bmpG[x, y] := getGValue(imgA.Canvas.Pixels[x, y]);
        bmpB[x, y] := getBValue(imgA.Canvas.Pixels[x, y]);
      end;
    end;
  end;
end;

procedure TVisibleWatermark.btnBlendClick(Sender: TObject);
var
  x, y, p: integer;
begin
  for y:=0 to imgResult.Height-1 do
  begin
    for x:=0 to imgResult.Width-1 do
    begin
      p := tBarParameter.Position;
      imgResult.Canvas.Pixels[x,y] := p * imgA.Canvas.Pixels[x, y] + (100 - p) * imgBlend.Canvas.Pixels[x, y];
    end;
  end;
end;

procedure TVisibleWatermark.btnLoadBClick(Sender: TObject);
var
  x, y: integer;
begin
  if OpenDialog.Execute then
  begin
    imgBlend.Picture.LoadFromFile(OpenDialog.FileName);
    for y:=0 to imgBlend.Height-1 do
    begin
      for x:=0 to imgBlend.Width-1 do
      begin
        bmpR[x, y] := getRValue(imgBlend.Canvas.Pixels[x, y]);
        bmpG[x, y] := getGValue(imgBlend.Canvas.Pixels[x, y]);
        bmpB[x, y] := getBValue(imgBlend.Canvas.Pixels[x, y]);
      end;
    end;
  end;
end;

procedure TVisibleWatermark.btnSaveClick(Sender: TObject);
begin
  if SaveDialog.Execute then
  begin
    imgResult.Picture.SaveToFile(SaveDialog.FileName);
  end;
end;

end.

