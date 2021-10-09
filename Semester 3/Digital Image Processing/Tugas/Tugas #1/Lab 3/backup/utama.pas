unit Utama;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  ComCtrls, MaskEdit;

type

  { TFormUtama }

  TFormUtama = class(TForm)
    btnLoad: TButton;
    btnSave: TButton;
    btnWarna: TButton;
    btnInvers: TButton;
    btnGray: TButton;
    btnBiner: TButton;
    btnBrightness: TButton;
    btnContrast: TButton;
    editG: TEdit;
    editContrast: TEdit;
    editBrightness: TEdit;
    editBiner: TEdit;
    imgOriginal: TImage;
    imgEdited: TImage;
    openDialog: TOpenDialog;
    saveDialog: TSaveDialog;
    tBarBiner: TTrackBar;
    tBarBrightness: TTrackBar;
    tBarContrast: TTrackBar;
    tBarG: TTrackBar;
    procedure btnBinerClick(Sender: TObject);
    procedure btnBrightnessClick(Sender: TObject);
    procedure btnContrastClick(Sender: TObject);
    procedure btnGrayClick(Sender: TObject);
    procedure btnInversClick(Sender: TObject);
    procedure btnLoadClick(Sender: TObject);
    procedure btnSaveClick(Sender: TObject);
    procedure btnWarnaClick(Sender: TObject);
    procedure editBinerChange(Sender: TObject);
    procedure editBrightnessChange(Sender: TObject);
    procedure editContrastChange(Sender: TObject);
    procedure editGChange(Sender: TObject);
    procedure tBarBinerChange(Sender: TObject);
    procedure tBarBrightnessChange(Sender: TObject);
    procedure tBarContrastChange(Sender: TObject);
    procedure tBarGChange(Sender: TObject);
  private

  public

  end;

var
  FormUtama: TFormUtama;

implementation

{$R *.lfm}

{ TFormUtama }

uses Windows;

var
  bmpR, bmpG, bmpB, bmpRR, bmpGG, bmpBB : array[0..1000, 0..1000] of byte;
  bmpBiner : array[0..1000, 0..1000] of boolean;
  modeWarna : byte;

procedure TFormUtama.btnLoadClick(Sender: TObject);
var
  x, y : integer;
begin
  if (openDialog.Execute) then
  begin
    imgOriginal.Picture.LoadFromFile(openDialog.FileName);
    imgEdited.Picture.LoadFromFile(openDialog.FileName);
    for y:=0 to imgOriginal.Height-1 do
    begin
      for x:=0 to imgOriginal.Width-1 do
      begin
        bmpR[x, y] := getRValue(imgOriginal.Canvas.Pixels[x, y]);
        bmpG[x, y] := getGValue(imgOriginal.Canvas.Pixels[x, y]);
        bmpB[x, y] := getBValue(imgOriginal.Canvas.Pixels[x, y]);
        bmpRR[x, y] := getRValue(imgOriginal.Canvas.Pixels[x, y]);
        bmpGG[x, y] := getGValue(imgOriginal.Canvas.Pixels[x, y]);
        bmpBB[x, y] := getBValue(imgOriginal.Canvas.Pixels[x, y]);
      end;
    end;
  end;
end;

procedure TFormUtama.btnGrayClick(Sender: TObject);
var
  x, y : integer;
  gray : byte;
begin
  for y:=0 to imgEdited.Height-1 do
  begin
    for x:=0 to imgEdited.Width-1 do
    begin
      gray := (bmpR[x, y] + bmpG[x, y] + bmpB[x, y]) div 3;
      imgEdited.Canvas.Pixels[x, y] := RGB(gray, gray, gray);
    end;
  end;
end;

procedure TFormUtama.btnBinerClick(Sender: TObject);
var
  x, y : integer;
  gray : byte;
begin
  for y:=0 to imgEdited.Height-1 do
  begin
    for x:=0 to imgEdited.Width-1 do
    begin
      gray := (bmpR[x, y] + bmpG[x, y] + bmpB[x, y]) div 3;
      if (gray <= tBarBiner.Position) then
      begin
        imgEdited.Canvas.Pixels[x, y] := RGB(0, 0, 0);
      end

      else
      begin
        imgEdited.Canvas.Pixels[x, y] := RGB(255, 255, 255);
      end;
    end;
  end;
end;

procedure TFormUtama.btnBrightnessClick(Sender: TObject);
var
  x, y : integer;
  brightnessR, brightnessG, brightnessB : integer;
begin
  for y:=0 to imgOriginal.Height-1 do
  begin
    for x:=0 to imgOriginal.Width-1 do
    begin
      brightnessR := bmpR[x, y] + tBarBrightness.Position;
      // Clipping R Channel Brightness
      if brightnessR < 0 then
         brightnessR := 0;
      if brightnessR > 255 then
         brightnessR := 255;

      brightnessG := bmpG[x, y] + tBarBrightness.Position;
      // Clipping G Channel Brightness
      if brightnessG < 0 then
         brightnessG := 0;
      if brightnessG > 255 then
         brightnessG := 255;

      brightnessB := bmpB[x, y] + tBarBrightness.Position;
      // Clipping B Channel Brightness
      if brightnessB < 0 then
         brightnessB := 0;
      if brightnessB > 255 then
         brightnessB := 255;
      imgEdited.Canvas.Pixels[x, y] := RGB(brightnessR, brightnessG, brightnessB);
    end;
  end;
end;

procedure TFormUtama.btnContrastClick(Sender: TObject);
var
  x, y, P, G : integer;
  contrastR, contrastG, contrastB : integer;
begin
  for y:=0 to imgOriginal.Height-1 do
  begin
    for x:=0 to imgOriginal.Width-1 do
    begin
      P := tBarContrast.Position;
      G := tBarG.Position;
      contrastR := G * (bmpR[x, y] - P) + P;
      // Clipping R Channel Contrast
      if contrastR < 0 then
         contrastR := 0;
      if contrastR > 255 then
         contrastR := 255;

      contrastG := G * (bmpG[x, y] - P) + P;
      // Clipping G Channel Contrast
      if contrastG < 0 then
         contrastG := 0;
      if contrastG > 255 then
         contrastG := 255;

      contrastB := G * (bmpB[x, y] - P) + P;
      // Clipping B Channel Contrast
      if contrastB < 0 then
         contrastB := 0;
      if contrastB > 255 then
         contrastB := 0;
      imgEdited.Canvas.Pixels[x, y] := RGB(contrastR, contrastG, contrastB);
    end;
  end;
end;

procedure TFormUtama.btnInversClick(Sender: TObject);
var
  x, y : integer;
  inversR, inversG, inversB : integer;
begin
  for y:=0 to imgOriginal.Height-1 do
  begin
    for x:=0 to imgOriginal.Width-1 do
    begin
      inversR := 255-bmpR[x, y];
      inversG := 255-bmpG[x, y];
      inversB := 255-bmpB[x, y];
      imgEdited.Canvas.Pixels[x, y] := RGB(inversR, inversG, inversB);
    end;
  end;
end;

procedure TFormUtama.btnSaveClick(Sender: TObject);
begin
  if (saveDialog.Execute) then
  begin
    imgEdited.Picture.SaveToFile(saveDialog.FileName);
  end;
end;

procedure TFormUtama.btnWarnaClick(Sender: TObject);
var
  x, y : integer;
begin
  for y:=0 to imgOriginal.Height-1 do
  begin
    for x:=0 to imgOriginal.Width-1 do
    begin
      bmpR[x, y] := bmpRR[x, y];
      bmpG[x, y] := bmpGG[x, y];
      bmpB[x, y] := bmpBB[x, y];
      imgOriginal.Canvas.Pixels[x, y] := RGB(bmpR[x, y], bmpG[x, y], bmpB[x, y]);
      imgEdited.Canvas.Pixels[x, y] := RGB(bmpRR[x, y], bmpG[x, y], bmpB[x, y]);
    end;
  end;
end;

procedure TFormUtama.editBinerChange(Sender: TObject);
begin
  editBiner.Text := IntToStr(tBarBiner.Position);
end;

procedure TFormUtama.editBrightnessChange(Sender: TObject);
begin
  editBrightness.Text := IntToStr(tBarBrightness.Position);
end;

procedure TFormUtama.editContrastChange(Sender: TObject);
begin
  editContrast.Text := IntToStr(tBarContrast.Position);
end;

procedure TFormUtama.editGChange(Sender: TObject);
begin
  editG.Text := IntToStr(tBarG.Position);
end;

procedure TFormUtama.tBarBinerChange(Sender: TObject);
begin
  editBiner.Text := IntToStr(tBarBiner.Position);
end;

procedure TFormUtama.tBarBrightnessChange(Sender: TObject);
begin
  editBrightness.Text := IntToStr(tBarBrightness.Position);
end;

procedure TFormUtama.tBarContrastChange(Sender: TObject);
begin
  editContrast.Text := IntToStr(tBarContrast.Position);
end;

procedure TFormUtama.tBarGChange(Sender: TObject);
begin
  editG.Text := IntToStr(tBarG.Position);
end;

end.

