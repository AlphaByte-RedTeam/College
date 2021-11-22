unit FormUtama;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  ComCtrls;

type

  { TFormMorphology }

  TFormMorphology = class(TForm)
    btnLoad: TButton;
    btnMorphAND: TButton;
    btnMorphAND3: TButton;
    btnMorphOR: TButton;
    btnSave: TButton;
    btnGray: TButton;
    btnBiner: TButton;
    btnMorph: TButton;
    editBiner: TEdit;
    imgMorphAND3: TImage;
    imgMorphOR: TImage;
    imgMorphAND: TImage;
    imgBiner: TImage;
    imgGray: TImage;
    imgOri: TImage;
    txtMorphAND: TLabel;
    txtMorphAND3: TLabel;
    txtMorphOR: TLabel;
    txtBiner: TLabel;
    txtGray: TLabel;
    txtOriginal: TLabel;
    openDialog: TOpenDialog;
    saveDialog: TSaveDialog;
    tBarBiner: TTrackBar;
    procedure btnBinerClick(Sender: TObject);
    procedure btnGrayClick(Sender: TObject);
    procedure btnLoadClick(Sender: TObject);
    procedure btnSaveClick(Sender: TObject);
    procedure editBinerChange(Sender: TObject);
    procedure tBarBinerChange(Sender: TObject);
  private

  public

  end;

var
  FormMorphology: TFormMorphology;

implementation

{$R *.lfm}

{ TFormMorphology }

uses Windows;

var
  bmpR, bmpG, bmpB: array[0..1000, 0..1000] of byte;

procedure TFormMorphology.btnLoadClick(Sender: TObject);
var
  x, y: integer;
begin
  if openDialog.Execute then
  begin
    imgOri.Picture.LoadFromFile(openDialog.FileName);
    for y:=0 to imgOri.Height-1 do
    begin
      for x:=0 to imgOri.Width-1 do
      begin
        bmpR[x,y] := getRValue(imgOri.Canvas.Pixels[x,y]);
        bmpG[x,y] := getGValue(imgOri.Canvas.Pixels[x,y]);
        bmpB[x,y] := getBValue(imgOri.Canvas.Pixels[x,y]);
      end;
    end;
  end;
end;

procedure TFormMorphology.btnGrayClick(Sender: TObject);
var
  x, y: integer;
  gray: byte;
begin
  for y:=0 to imgGray.Height-1 do
  begin
    for x:=0 to imgGray.Width-1 do
    begin
      gray := (bmpR[x,y] + bmpG[x,y] + bmpB[x,y]) div 3;
      imgGray.Canvas.Pixels[x,y] := RGB(gray, gray, gray);
    end;
  end;
end;

procedure TFormMorphology.btnBinerClick(Sender: TObject);
var
  x, y: integer;
  gray: byte;
begin
  for y:=0 to imgBiner.Height-1 do
  begin
    for x:=0 to imgBiner.Width-1 do
    begin
      gray := (bmpR[x,y] + bmpG[x,y] + bmpB[x,y]) div 3;
      if (gray <= tBarBiner.Position) then
      begin
        imgBiner.Canvas.Pixels[x,y] := RGB(0, 0, 0);
      end

      else
      begin
        imgBiner.Canvas.Pixels[x,y] := RGB(255, 255, 255);
      end;
    end;
  end;
end;

procedure TFormMorphology.btnSaveClick(Sender: TObject);
var
  x, y: integer;
begin
  if saveDialog.Execute then
  begin
    imgMorphAND.Picture.SaveToFile(SaveDialog.FileName);
  end;
end;

procedure TFormMorphology.editBinerChange(Sender: TObject);
begin
  editBiner.Text := IntToStr(tBarBiner.Position);
end;

procedure TFormMorphology.tBarBinerChange(Sender: TObject);
begin
  editBiner.Text := IntToStr(tBarBiner.Position);
end;

end.

