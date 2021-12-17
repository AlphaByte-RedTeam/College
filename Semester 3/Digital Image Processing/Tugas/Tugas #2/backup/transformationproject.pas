unit TransformationProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls,
  ComCtrls, CheckLst, Buttons;

type

  { TtranformationForm }

  TtranformationForm = class(TForm)
    btnLoad: TButton;
    checkCenter: TCheckBox;
    imgOriginal: TPaintBox;
    openDialog: TOpenDialog;
    tBarZoom: TTrackBar;
    tBarX: TTrackBar;
    tBarY: TTrackBar;
    procedure btnLoadClick(Sender: TObject);
    procedure checkCenterChange(Sender: TObject);
    procedure imgOriginalPaint(Sender: TObject);
  private

  public

  end;

var
  tranformationForm: TtranformationForm;

implementation

{$R *.lfm}

{ TtranformationForm }

uses Windows;

var
  loadedImg: TPicture = nil;

procedure TtranformationForm.btnLoadClick(Sender: TObject);
begin
  if not (openDialog.Execute) then Exit;

  if (loadedImg = nil) then loadedImg := TPicture.Create;
  loadedImg.LoadFromFile(openDialog.FileName);
  tBarZoom.Position := 100;
  tBarX.Position := 0;
  tBarY.Position := 0;
  imgOriginal.Invalidate;
end;

procedure TtranformationForm.checkCenterChange(Sender: TObject);
begin
  imgOriginal.Invalidate;
end;

procedure TtranformationForm.imgOriginalPaint(Sender: TObject);
var
  imgPos: TRect;
  scale: Real;
  newWidth: Integer;
  newHeight: Integer;
  x, y: Integer;
begin
  if not (loadedImg = nil) then
  begin
    // Calculate zoom and size
    scale := imgOriginal.Height / loadedImg.Height;
    newHeight := Round(loadedImg.Height * (tBarZoom.Position / 100) * scale);
    newWidth := Round(loadedImg.Width * (tBarZoom.Position / 100) * scale);

    // Center image with screen viewPort
    x := (imgOriginal.Width - newWidth) div 2;
    y := (imgOriginal.Height - newHeight) div 2;

    // Offset the image position
    x := x + Round(loadedImg.Width * tBarX.Position * scale) div 100;
    y := y + (imgOriginal.Height * tBarY.Position) div 100;

    // Show the image
    imgPos.Left := x;
    imgPos.Right := imgPos.Left + newWidth;
    imgPos.Top := y;
    imgPos.Bottom := imgPos.Top + newHeight;
    imgOriginal.Canvas.StretchDraw(imgPos, loadedImg.Graphic);
  end;

  // Draw center lines
  if checkCenter.Checked then
     with imgOriginal, imgOriginal.Canvas do
     begin
       x := width div 2;
       y := height div 2;
       Pen.Color := clLime;
       Line(x, 0, x, height);
       Line(0, y, width, y);
     end;
end;

end.

