#include "awtk_cpp.hpp"

uint32_t TEvent::GetType() {
  return event_get_type(((event_t*)(this->nativeObj)));
}

TEvent TEvent::Create(uint32_t type) {
  return TEvent((event_t*)(event_create(type)));
}

ret_t TEvent::Destroy() {
  return event_destroy(((event_t*)(this->nativeObj)));
}

int32_t TEvent::GetType() const {
  return ((event_t*)(this->nativeObj))->type;
}

int32_t TEvent::GetSize() const {
  return ((event_t*)(this->nativeObj))->size;
}

uint64_t TEvent::GetTime() const {
  return ((event_t*)(this->nativeObj))->time;
}

void* TEvent::GetTarget() const {
  return ((event_t*)(this->nativeObj))->target;
}

TEmitter TEmitter::Create() {
  return TEmitter((emitter_t*)(emitter_create()));
}

ret_t TEmitter::Dispatch(TEvent& e) {
  return emitter_dispatch(((emitter_t*)(this->nativeObj)), ((event_t*)(e.nativeObj)));
}

ret_t TEmitter::DispatchSimpleEvent(uint32_t type) {
  return emitter_dispatch_simple_event(((emitter_t*)(this->nativeObj)), type);
}

uint32_t TEmitter::On(event_type_t etype, event_func_t handler, void* ctx) {
  return emitter_on(((emitter_t*)(this->nativeObj)), etype, handler, ctx);
}

ret_t TEmitter::Off(uint32_t id) {
  return emitter_off(((emitter_t*)(this->nativeObj)), id);
}

ret_t TEmitter::Enable() {
  return emitter_enable(((emitter_t*)(this->nativeObj)));
}

ret_t TEmitter::Disable() {
  return emitter_disable(((emitter_t*)(this->nativeObj)));
}

ret_t TEmitter::Destroy() {
  return emitter_destroy(((emitter_t*)(this->nativeObj)));
}

float TRectf::GetX() const {
  return ((rectf_t*)(this->nativeObj))->x;
}

float TRectf::GetY() const {
  return ((rectf_t*)(this->nativeObj))->y;
}

float TRectf::GetW() const {
  return ((rectf_t*)(this->nativeObj))->w;
}

float TRectf::GetH() const {
  return ((rectf_t*)(this->nativeObj))->h;
}

TRect TRect::Create(xy_t x, xy_t y, wh_t w, wh_t h) {
  return TRect((rect_t*)(rect_create(x, y, w, h)));
}

TRect TRect::Set(xy_t x, xy_t y, wh_t w, wh_t h) {
  return TRect((rect_t*)(rect_set(((rect_t*)(this->nativeObj)), x, y, w, h)));
}

ret_t TRect::Destroy() {
  return rect_destroy(((rect_t*)(this->nativeObj)));
}

xy_t TRect::GetX() const {
  return ((rect_t*)(this->nativeObj))->x;
}

xy_t TRect::GetY() const {
  return ((rect_t*)(this->nativeObj))->y;
}

wh_t TRect::GetW() const {
  return ((rect_t*)(this->nativeObj))->w;
}

wh_t TRect::GetH() const {
  return ((rect_t*)(this->nativeObj))->h;
}

TBitmap TBitmap::Create() {
  return TBitmap((bitmap_t*)(bitmap_create()));
}

TBitmap TBitmap::CreateEx(uint32_t w, uint32_t h, uint32_t line_length, bitmap_format_t format) {
  return TBitmap((bitmap_t*)(bitmap_create_ex(w, h, line_length, format)));
}

uint32_t TBitmap::GetBpp() {
  return bitmap_get_bpp(((bitmap_t*)(this->nativeObj)));
}

ret_t TBitmap::Destroy() {
  return bitmap_destroy_with_self(((bitmap_t*)(this->nativeObj)));
}

uint32_t TBitmap::GetBppOfFormat(bitmap_format_t format) {
  return bitmap_get_bpp_of_format(format);
}

wh_t TBitmap::GetW() const {
  return ((bitmap_t*)(this->nativeObj))->w;
}

wh_t TBitmap::GetH() const {
  return ((bitmap_t*)(this->nativeObj))->h;
}

uint32_t TBitmap::GetLineLength() const {
  return ((bitmap_t*)(this->nativeObj))->line_length;
}

uint16_t TBitmap::GetFlags() const {
  return ((bitmap_t*)(this->nativeObj))->flags;
}

uint16_t TBitmap::GetFormat() const {
  return ((bitmap_t*)(this->nativeObj))->format;
}

const char* TBitmap::GetName() const {
  return ((bitmap_t*)(this->nativeObj))->name;
}

ret_t TObject::Unref() {
  return object_unref(((object_t*)(this->nativeObj)));
}

TObject TObject::Ref(TObject& obj) {
  return TObject((emitter_t*)(object_ref(((object_t*)(obj.nativeObj)))));
}

const char* TObject::GetType() {
  return object_get_type(((object_t*)(this->nativeObj)));
}

const char* TObject::GetDesc() {
  return object_get_desc(((object_t*)(this->nativeObj)));
}

uint32_t TObject::GetSize() {
  return object_get_size(((object_t*)(this->nativeObj)));
}

bool TObject::IsCollection() {
  return object_is_collection(((object_t*)(this->nativeObj)));
}

ret_t TObject::SetName(const char* name) {
  return object_set_name(((object_t*)(this->nativeObj)), name);
}

int TObject::Compare(TObject& other) {
  return object_compare(((object_t*)(this->nativeObj)), ((object_t*)(other.nativeObj)));
}

ret_t TObject::GetProp(const char* name, TValue& v) {
  return object_get_prop(((object_t*)(this->nativeObj)), name, ((value_t*)(v.nativeObj)));
}

const char* TObject::GetPropStr(const char* name) {
  return object_get_prop_str(((object_t*)(this->nativeObj)), name);
}

void* TObject::GetPropPointer(const char* name) {
  return object_get_prop_pointer(((object_t*)(this->nativeObj)), name);
}

TObject TObject::GetPropObject(const char* name) {
  return TObject((emitter_t*)(object_get_prop_object(((object_t*)(this->nativeObj)), name)));
}

int32_t TObject::GetPropInt(const char* name, int32_t defval) {
  return object_get_prop_int(((object_t*)(this->nativeObj)), name, defval);
}

bool TObject::GetPropBool(const char* name, bool defval) {
  return object_get_prop_bool(((object_t*)(this->nativeObj)), name, defval);
}

float_t TObject::GetPropFloat(const char* name, float_t defval) {
  return object_get_prop_float(((object_t*)(this->nativeObj)), name, defval);
}

double TObject::GetPropDouble(const char* name, double defval) {
  return object_get_prop_double(((object_t*)(this->nativeObj)), name, defval);
}

ret_t TObject::RemoveProp(const char* name) {
  return object_remove_prop(((object_t*)(this->nativeObj)), name);
}

ret_t TObject::SetProp(const char* name, TValue& value) {
  return object_set_prop(((object_t*)(this->nativeObj)), name, ((value_t*)(value.nativeObj)));
}

ret_t TObject::SetPropStr(const char* name, const char* value) {
  return object_set_prop_str(((object_t*)(this->nativeObj)), name, value);
}

ret_t TObject::SetPropObject(const char* name, TObject& value) {
  return object_set_prop_object(((object_t*)(this->nativeObj)), name,
                                ((object_t*)(value.nativeObj)));
}

ret_t TObject::SetPropInt(const char* name, int32_t value) {
  return object_set_prop_int(((object_t*)(this->nativeObj)), name, value);
}

ret_t TObject::SetPropBool(const char* name, bool value) {
  return object_set_prop_bool(((object_t*)(this->nativeObj)), name, value);
}

ret_t TObject::SetPropFloat(const char* name, float_t value) {
  return object_set_prop_float(((object_t*)(this->nativeObj)), name, value);
}

ret_t TObject::SetPropDouble(const char* name, double value) {
  return object_set_prop_double(((object_t*)(this->nativeObj)), name, value);
}

ret_t TObject::CopyProp(TObject& src, const char* name) {
  return object_copy_prop(((object_t*)(this->nativeObj)), ((object_t*)(src.nativeObj)), name);
}

bool TObject::HasProp(const char* name) {
  return object_has_prop(((object_t*)(this->nativeObj)), name);
}

ret_t TObject::Eval(const char* expr, TValue& v) {
  return object_eval(((object_t*)(this->nativeObj)), expr, ((value_t*)(v.nativeObj)));
}

bool TObject::CanExec(const char* name, const char* args) {
  return object_can_exec(((object_t*)(this->nativeObj)), name, args);
}

ret_t TObject::Execute(const char* name, const char* args) {
  return object_exec(((object_t*)(this->nativeObj)), name, args);
}

ret_t TObject::NotifyChanged() {
  return object_notify_changed(((object_t*)(this->nativeObj)));
}

bool TObject::HasPropByPath(const char* path) {
  return object_has_prop_by_path(((object_t*)(this->nativeObj)), path);
}

const char* TObject::GetPropStrByPath(const char* path) {
  return object_get_prop_str_by_path(((object_t*)(this->nativeObj)), path);
}

void* TObject::GetPropPointerByPath(const char* path) {
  return object_get_prop_pointer_by_path(((object_t*)(this->nativeObj)), path);
}

TObject TObject::GetPropObjectByPath(const char* path) {
  return TObject(
      (emitter_t*)(object_get_prop_object_by_path(((object_t*)(this->nativeObj)), path)));
}

int32_t TObject::GetPropIntByPath(const char* path, int32_t defval) {
  return object_get_prop_int_by_path(((object_t*)(this->nativeObj)), path, defval);
}

bool TObject::GetPropBoolByPath(const char* path, bool defval) {
  return object_get_prop_bool_by_path(((object_t*)(this->nativeObj)), path, defval);
}

float_t TObject::GetPropFloatByPath(const char* path, float_t defval) {
  return object_get_prop_float_by_path(((object_t*)(this->nativeObj)), path, defval);
}

ret_t TObject::SetPropByPath(const char* path, TValue& value) {
  return object_set_prop_by_path(((object_t*)(this->nativeObj)), path,
                                 ((value_t*)(value.nativeObj)));
}

ret_t TObject::SetPropStrByPath(const char* path, const char* value) {
  return object_set_prop_str_by_path(((object_t*)(this->nativeObj)), path, value);
}

ret_t TObject::SetPropObjectByPath(const char* path, TObject& value) {
  return object_set_prop_object_by_path(((object_t*)(this->nativeObj)), path,
                                        ((object_t*)(value.nativeObj)));
}

ret_t TObject::SetPropIntByPath(const char* path, int32_t value) {
  return object_set_prop_int_by_path(((object_t*)(this->nativeObj)), path, value);
}

ret_t TObject::SetPropBoolByPath(const char* path, bool value) {
  return object_set_prop_bool_by_path(((object_t*)(this->nativeObj)), path, value);
}

ret_t TObject::SetPropFloatByPath(const char* path, float_t value) {
  return object_set_prop_float_by_path(((object_t*)(this->nativeObj)), path, value);
}

bool TObject::CanExecByPath(const char* path, const char* args) {
  return object_can_exec_by_path(((object_t*)(this->nativeObj)), path, args);
}

ret_t TObject::ExecuteByPath(const char* path, const char* args) {
  return object_exec_by_path(((object_t*)(this->nativeObj)), path, args);
}

int8_t TObject::GetPropInt8(const char* name, int8_t defval) {
  return object_get_prop_int8(((object_t*)(this->nativeObj)), name, defval);
}

ret_t TObject::SetPropInt8(const char* name, int8_t value) {
  return object_set_prop_int8(((object_t*)(this->nativeObj)), name, value);
}

uint8_t TObject::GetPropUint8(const char* name, uint8_t defval) {
  return object_get_prop_uint8(((object_t*)(this->nativeObj)), name, defval);
}

ret_t TObject::SetPropUint8(const char* name, uint8_t value) {
  return object_set_prop_uint8(((object_t*)(this->nativeObj)), name, value);
}

int16_t TObject::GetPropInt16(const char* name, int16_t defval) {
  return object_get_prop_int16(((object_t*)(this->nativeObj)), name, defval);
}

ret_t TObject::SetPropInt16(const char* name, int16_t value) {
  return object_set_prop_int16(((object_t*)(this->nativeObj)), name, value);
}

uint16_t TObject::GetPropUint16(const char* name, uint16_t defval) {
  return object_get_prop_uint16(((object_t*)(this->nativeObj)), name, defval);
}

ret_t TObject::SetPropUint16(const char* name, uint16_t value) {
  return object_set_prop_uint16(((object_t*)(this->nativeObj)), name, value);
}

int32_t TObject::GetPropInt32(const char* name, int32_t defval) {
  return object_get_prop_int32(((object_t*)(this->nativeObj)), name, defval);
}

ret_t TObject::SetPropInt32(const char* name, int32_t value) {
  return object_set_prop_int32(((object_t*)(this->nativeObj)), name, value);
}

uint32_t TObject::GetPropUint32(const char* name, uint32_t defval) {
  return object_get_prop_uint32(((object_t*)(this->nativeObj)), name, defval);
}

ret_t TObject::SetPropUint32(const char* name, uint32_t value) {
  return object_set_prop_uint32(((object_t*)(this->nativeObj)), name, value);
}

int64_t TObject::GetPropInt64(const char* name, int64_t defval) {
  return object_get_prop_int64(((object_t*)(this->nativeObj)), name, defval);
}

ret_t TObject::SetPropInt64(const char* name, int64_t value) {
  return object_set_prop_int64(((object_t*)(this->nativeObj)), name, value);
}

uint64_t TObject::GetPropUint64(const char* name, uint64_t defval) {
  return object_get_prop_uint64(((object_t*)(this->nativeObj)), name, defval);
}

ret_t TObject::SetPropUint64(const char* name, uint64_t value) {
  return object_set_prop_uint64(((object_t*)(this->nativeObj)), name, value);
}

int32_t TObject::GetRefCount() const {
  return ((object_t*)(this->nativeObj))->ref_count;
}

char* TObject::GetName() const {
  return ((object_t*)(this->nativeObj))->name;
}

TValue TValue::SetBool(bool value) {
  return TValue((value_t*)(value_set_bool(((value_t*)(this->nativeObj)), value)));
}

bool TValue::Bool() {
  return value_bool(((value_t*)(this->nativeObj)));
}

TValue TValue::SetInt8(int8_t value) {
  return TValue((value_t*)(value_set_int8(((value_t*)(this->nativeObj)), value)));
}

int8_t TValue::Int8() {
  return value_int8(((value_t*)(this->nativeObj)));
}

TValue TValue::SetUint8(uint8_t value) {
  return TValue((value_t*)(value_set_uint8(((value_t*)(this->nativeObj)), value)));
}

int8_t TValue::Uint8() {
  return value_uint8(((value_t*)(this->nativeObj)));
}

TValue TValue::SetInt16(int16_t value) {
  return TValue((value_t*)(value_set_int16(((value_t*)(this->nativeObj)), value)));
}

int16_t TValue::Int16() {
  return value_int16(((value_t*)(this->nativeObj)));
}

TValue TValue::SetUint16(uint16_t value) {
  return TValue((value_t*)(value_set_uint16(((value_t*)(this->nativeObj)), value)));
}

uint16_t TValue::Uint16() {
  return value_uint16(((value_t*)(this->nativeObj)));
}

TValue TValue::SetInt32(int32_t value) {
  return TValue((value_t*)(value_set_int32(((value_t*)(this->nativeObj)), value)));
}

int32_t TValue::Int32() {
  return value_int32(((value_t*)(this->nativeObj)));
}

TValue TValue::SetUint32(uint32_t value) {
  return TValue((value_t*)(value_set_uint32(((value_t*)(this->nativeObj)), value)));
}

TValue TValue::SetInt64(int64_t value) {
  return TValue((value_t*)(value_set_int64(((value_t*)(this->nativeObj)), value)));
}

int64_t TValue::Int64() {
  return value_int64(((value_t*)(this->nativeObj)));
}

TValue TValue::SetUint64(uint64_t value) {
  return TValue((value_t*)(value_set_uint64(((value_t*)(this->nativeObj)), value)));
}

uint64_t TValue::Uint64() {
  return value_uint64(((value_t*)(this->nativeObj)));
}

TValue TValue::SetFloat(float_t value) {
  return TValue((value_t*)(value_set_float(((value_t*)(this->nativeObj)), value)));
}

float TValue::Float32() {
  return value_float32(((value_t*)(this->nativeObj)));
}

TValue TValue::SetFloat64(double value) {
  return TValue((value_t*)(value_set_double(((value_t*)(this->nativeObj)), value)));
}

double TValue::Float64() {
  return value_double(((value_t*)(this->nativeObj)));
}

TValue TValue::SetStr(const char* value) {
  return TValue((value_t*)(value_dup_str(((value_t*)(this->nativeObj)), value)));
}

const char* TValue::Str() {
  return value_str(((value_t*)(this->nativeObj)));
}

const char* TValue::StrEx(char* buff, uint32_t size) {
  return value_str_ex(((value_t*)(this->nativeObj)), buff, size);
}

bool TValue::IsNull() {
  return value_is_null(((value_t*)(this->nativeObj)));
}

TValue TValue::SetInt(int32_t value) {
  return TValue((value_t*)(value_set_int(((value_t*)(this->nativeObj)), value)));
}

TValue TValue::SetObject(TObject& value) {
  return TValue(
      (value_t*)(value_set_object(((value_t*)(this->nativeObj)), ((object_t*)(value.nativeObj)))));
}

TObject TValue::Object() {
  return TObject((emitter_t*)(value_object(((value_t*)(this->nativeObj)))));
}

TValue TValue::SetToken(uint32_t value) {
  return TValue((value_t*)(value_set_token(((value_t*)(this->nativeObj)), value)));
}

uint32_t TValue::Token() {
  return value_token(((value_t*)(this->nativeObj)));
}

TValue TValue::Create() {
  return TValue((value_t*)(value_create()));
}

ret_t TValue::Destroy() {
  return value_destroy(((value_t*)(this->nativeObj)));
}

ret_t TValue::Reset() {
  return value_reset(((value_t*)(this->nativeObj)));
}

ret_t TGlobal::Init(wh_t w, wh_t h, app_type_t app_type, const char* app_name,
                    const char* app_root) {
  return tk_init(w, h, app_type, app_name, app_root);
}

ret_t TGlobal::Run() {
  return tk_run();
}

ret_t TGlobal::Quit() {
  return tk_quit();
}

int32_t TGlobal::GetPointerX() {
  return tk_get_pointer_x();
}

int32_t TGlobal::GetPointerY() {
  return tk_get_pointer_y();
}

bool TGlobal::IsPointerPressed() {
  return tk_is_pointer_pressed();
}

wh_t TCanvas::GetWidth() {
  return canvas_get_width(((canvas_t*)(this->nativeObj)));
}

wh_t TCanvas::GetHeight() {
  return canvas_get_height(((canvas_t*)(this->nativeObj)));
}

ret_t TCanvas::GetClipRect(TRect& r) {
  return canvas_get_clip_rect(((canvas_t*)(this->nativeObj)), ((rect_t*)(r.nativeObj)));
}

ret_t TCanvas::SetClipRect(TRect& r) {
  return canvas_set_clip_rect(((canvas_t*)(this->nativeObj)), ((const rect_t*)(r.nativeObj)));
}

ret_t TCanvas::SetClipRectEx(TRect& r, bool translate) {
  return canvas_set_clip_rect_ex(((canvas_t*)(this->nativeObj)), ((const rect_t*)(r.nativeObj)),
                                 translate);
}

ret_t TCanvas::SetFillColor(const char* color) {
  return canvas_set_fill_color_str(((canvas_t*)(this->nativeObj)), color);
}

ret_t TCanvas::SetTextColor(const char* color) {
  return canvas_set_text_color_str(((canvas_t*)(this->nativeObj)), color);
}

ret_t TCanvas::SetStrokeColor(const char* color) {
  return canvas_set_stroke_color_str(((canvas_t*)(this->nativeObj)), color);
}

ret_t TCanvas::SetGlobalAlpha(uint8_t alpha) {
  return canvas_set_global_alpha(((canvas_t*)(this->nativeObj)), alpha);
}

ret_t TCanvas::Translate(xy_t dx, xy_t dy) {
  return canvas_translate(((canvas_t*)(this->nativeObj)), dx, dy);
}

ret_t TCanvas::Untranslate(xy_t dx, xy_t dy) {
  return canvas_untranslate(((canvas_t*)(this->nativeObj)), dx, dy);
}

ret_t TCanvas::DrawVline(xy_t x, xy_t y, wh_t h) {
  return canvas_draw_vline(((canvas_t*)(this->nativeObj)), x, y, h);
}

ret_t TCanvas::DrawHline(xy_t x, xy_t y, wh_t w) {
  return canvas_draw_hline(((canvas_t*)(this->nativeObj)), x, y, w);
}

ret_t TCanvas::FillRect(xy_t x, xy_t y, wh_t w, wh_t h) {
  return canvas_fill_rect(((canvas_t*)(this->nativeObj)), x, y, w, h);
}

ret_t TCanvas::ClearRect(xy_t x, xy_t y, wh_t w, wh_t h) {
  return canvas_clear_rect(((canvas_t*)(this->nativeObj)), x, y, w, h);
}

ret_t TCanvas::StrokeRect(xy_t x, xy_t y, wh_t w, wh_t h) {
  return canvas_stroke_rect(((canvas_t*)(this->nativeObj)), x, y, w, h);
}

ret_t TCanvas::SetFont(const char* name, font_size_t size) {
  return canvas_set_font(((canvas_t*)(this->nativeObj)), name, size);
}

float_t TCanvas::MeasureText(const char* str) {
  return canvas_measure_utf8(((canvas_t*)(this->nativeObj)), str);
}

ret_t TCanvas::DrawText(const char* str, xy_t x, xy_t y) {
  return canvas_draw_utf8(((canvas_t*)(this->nativeObj)), str, x, y);
}

ret_t TCanvas::DrawTextInRect(const char* str, TRect& r) {
  return canvas_draw_utf8_in_rect(((canvas_t*)(this->nativeObj)), str,
                                  ((const rect_t*)(r.nativeObj)));
}

ret_t TCanvas::DrawIcon(TBitmap& img, xy_t cx, xy_t cy) {
  return canvas_draw_icon(((canvas_t*)(this->nativeObj)), ((bitmap_t*)(img.nativeObj)), cx, cy);
}

ret_t TCanvas::DrawImage(TBitmap& img, TRect& src, TRect& dst) {
  return canvas_draw_image(((canvas_t*)(this->nativeObj)), ((bitmap_t*)(img.nativeObj)),
                           ((const rect_t*)(src.nativeObj)), ((const rect_t*)(dst.nativeObj)));
}

ret_t TCanvas::DrawImageEx(TBitmap& img, image_draw_type_t draw_type, TRect& dst) {
  return canvas_draw_image_ex(((canvas_t*)(this->nativeObj)), ((bitmap_t*)(img.nativeObj)),
                              draw_type, ((const rect_t*)(dst.nativeObj)));
}

ret_t TCanvas::DrawImageEx2(TBitmap& img, image_draw_type_t draw_type, TRect& src, TRect& dst) {
  return canvas_draw_image_ex2(((canvas_t*)(this->nativeObj)), ((bitmap_t*)(img.nativeObj)),
                               draw_type, ((const rect_t*)(src.nativeObj)),
                               ((const rect_t*)(dst.nativeObj)));
}

TVgcanvas TCanvas::GetVgcanvas() {
  return TVgcanvas((vgcanvas_t*)(canvas_get_vgcanvas(((canvas_t*)(this->nativeObj)))));
}

ret_t TCanvas::Reset() {
  return canvas_reset(((canvas_t*)(this->nativeObj)));
}

xy_t TCanvas::GetOx() const {
  return ((canvas_t*)(this->nativeObj))->ox;
}

xy_t TCanvas::GetOy() const {
  return ((canvas_t*)(this->nativeObj))->oy;
}

char* TCanvas::GetFontName() const {
  return ((canvas_t*)(this->nativeObj))->font_name;
}

uint16_t TCanvas::GetFontSize() const {
  return ((canvas_t*)(this->nativeObj))->font_size;
}

uint8_t TCanvas::GetGlobalAlpha() const {
  return ((canvas_t*)(this->nativeObj))->global_alpha;
}

ret_t TClipBoard::SetText(const char* text) {
  return clip_board_set_text(text);
}

const char* TClipBoard::GetText() {
  return clip_board_get_text();
}

ret_t TFontManager::UnloadFont(char* name, font_size_t size) {
  return font_manager_unload_font(((font_manager_t*)(this->nativeObj)), name, size);
}

ret_t TFontManager::ShrinkCache(uint32_t cache_size) {
  return font_manager_shrink_cache(((font_manager_t*)(this->nativeObj)), cache_size);
}

ret_t TFontManager::UnloadAll() {
  return font_manager_unload_all(((font_manager_t*)(this->nativeObj)));
}

uint32_t TIdle::Add(idle_func_t on_idle, void* ctx) {
  return idle_add(on_idle, ctx);
}

ret_t TIdle::Remove(uint32_t idle_id) {
  return idle_remove(idle_id);
}

ret_t TIdle::RemoveAllByCtx(void* ctx) {
  return idle_remove_all_by_ctx(ctx);
}

TImageManager TImageManager::Instance() {
  return TImageManager((image_manager_t*)(image_manager()));
}

ret_t TImageManager::GetBitmap(char* name, TBitmap& image) {
  return image_manager_get_bitmap(((image_manager_t*)(this->nativeObj)), name,
                                  ((bitmap_t*)(image.nativeObj)));
}

ret_t TImageManager::Preload(char* name) {
  return image_manager_preload(((image_manager_t*)(this->nativeObj)), name);
}

ret_t TInputMethod::CommitText(const char* text) {
  return input_method_commit_text(((input_method_t*)(this->nativeObj)), text);
}

ret_t TInputMethod::SetLang(const char* lang) {
  return input_method_set_lang(((input_method_t*)(this->nativeObj)), lang);
}

const char* TInputMethod::GetLang() {
  return input_method_get_lang(((input_method_t*)(this->nativeObj)));
}

ret_t TInputMethod::DispatchKey(uint32_t key) {
  return input_method_dispatch_key(((input_method_t*)(this->nativeObj)), key);
}

ret_t TInputMethod::DispatchKeys(const char* key) {
  return input_method_dispatch_keys(((input_method_t*)(this->nativeObj)), key);
}

ret_t TInputMethod::DispatchPreedit() {
  return input_method_dispatch_preedit(((input_method_t*)(this->nativeObj)));
}

ret_t TInputMethod::DispatchPreeditConfirm() {
  return input_method_dispatch_preedit_confirm(((input_method_t*)(this->nativeObj)));
}

ret_t TInputMethod::DispatchPreeditAbort() {
  return input_method_dispatch_preedit_abort(((input_method_t*)(this->nativeObj)));
}

TInputMethod TInputMethod::Instance() {
  return TInputMethod((input_method_t*)(input_method()));
}

TLocaleInfo TLocaleInfo::Instance() {
  return TLocaleInfo((locale_info_t*)(locale_info()));
}

const char* TLocaleInfo::Tr(const char* text) {
  return locale_info_tr(((locale_info_t*)(this->nativeObj)), text);
}

ret_t TLocaleInfo::Change(char* language, char* country) {
  return locale_info_change(((locale_info_t*)(this->nativeObj)), language, country);
}

ret_t TLocaleInfo::Off(uint32_t id) {
  return locale_info_off(((locale_info_t*)(this->nativeObj)), id);
}

ret_t TStyle::NotifyWidgetStateChanged(TWidget& widget) {
  return style_notify_widget_state_changed(((style_t*)(this->nativeObj)),
                                           ((widget_t*)(widget.nativeObj)));
}

bool TStyle::IsValid() {
  return style_is_valid(((style_t*)(this->nativeObj)));
}

int32_t TStyle::GetInt(const char* name, int32_t defval) {
  return style_get_int(((style_t*)(this->nativeObj)), name, defval);
}

uint32_t TStyle::GetUint(const char* name, uint32_t defval) {
  return style_get_uint(((style_t*)(this->nativeObj)), name, defval);
}

const char* TStyle::GetStr(const char* name, const char* defval) {
  return style_get_str(((style_t*)(this->nativeObj)), name, defval);
}

ret_t TStyle::Set(const char* state, const char* name, TValue& value) {
  return style_set(((style_t*)(this->nativeObj)), state, name, ((const value_t*)(value.nativeObj)));
}

ret_t TStyle::UpdateState(TTheme& theme, const char* widget_type, const char* style_name,
                          const char* widget_state) {
  return style_update_state(((style_t*)(this->nativeObj)), ((theme_t*)(theme.nativeObj)),
                            widget_type, style_name, widget_state);
}

const char* TStyle::GetStyleState() {
  return style_get_style_state(((style_t*)(this->nativeObj)));
}

bool TStyle::IsMutable() {
  return style_is_mutable(((style_t*)(this->nativeObj)));
}

const char* TStyle::GetStyleType() {
  return style_get_style_type(((style_t*)(this->nativeObj)));
}

TTheme TTheme::Instance() {
  return TTheme((theme_t*)(theme()));
}

uint32_t TTimer::Add(timer_func_t on_timer, void* ctx, uint32_t duration) {
  return timer_add(on_timer, ctx, duration);
}

ret_t TTimer::Remove(uint32_t timer_id) {
  return timer_remove(timer_id);
}

ret_t TTimer::RemoveAllByCtx(void* ctx) {
  return timer_remove_all_by_ctx(ctx);
}

ret_t TTimer::Reset(uint32_t timer_id) {
  return timer_reset(timer_id);
}

ret_t TTimer::Suspend(uint32_t timer_id) {
  return timer_suspend(timer_id);
}

ret_t TTimer::Resume(uint32_t timer_id) {
  return timer_resume(timer_id);
}

ret_t TTimer::Modify(uint32_t timer_id, uint32_t duration) {
  return timer_modify(timer_id, duration);
}

ret_t TVgcanvas::Flush() {
  return vgcanvas_flush(((vgcanvas_t*)(this->nativeObj)));
}

ret_t TVgcanvas::BeginPath() {
  return vgcanvas_begin_path(((vgcanvas_t*)(this->nativeObj)));
}

ret_t TVgcanvas::MoveTo(float_t x, float_t y) {
  return vgcanvas_move_to(((vgcanvas_t*)(this->nativeObj)), x, y);
}

ret_t TVgcanvas::LineTo(float_t x, float_t y) {
  return vgcanvas_line_to(((vgcanvas_t*)(this->nativeObj)), x, y);
}

ret_t TVgcanvas::QuadTo(float_t cpx, float_t cpy, float_t x, float_t y) {
  return vgcanvas_quad_to(((vgcanvas_t*)(this->nativeObj)), cpx, cpy, x, y);
}

ret_t TVgcanvas::BezierTo(float_t cp1x, float_t cp1y, float_t cp2x, float_t cp2y, float_t x,
                          float_t y) {
  return vgcanvas_bezier_to(((vgcanvas_t*)(this->nativeObj)), cp1x, cp1y, cp2x, cp2y, x, y);
}

ret_t TVgcanvas::ArcTo(float_t x1, float_t y1, float_t x2, float_t y2, float_t r) {
  return vgcanvas_arc_to(((vgcanvas_t*)(this->nativeObj)), x1, y1, x2, y2, r);
}

ret_t TVgcanvas::Arc(float_t x, float_t y, float_t r, float_t start_angle, float_t end_angle,
                     bool ccw) {
  return vgcanvas_arc(((vgcanvas_t*)(this->nativeObj)), x, y, r, start_angle, end_angle, ccw);
}

bool TVgcanvas::IsPointInPath(float_t x, float_t y) {
  return vgcanvas_is_point_in_path(((vgcanvas_t*)(this->nativeObj)), x, y);
}

ret_t TVgcanvas::Rect(float_t x, float_t y, float_t w, float_t h) {
  return vgcanvas_rect(((vgcanvas_t*)(this->nativeObj)), x, y, w, h);
}

ret_t TVgcanvas::RoundedRect(float_t x, float_t y, float_t w, float_t h, float_t r) {
  return vgcanvas_rounded_rect(((vgcanvas_t*)(this->nativeObj)), x, y, w, h, r);
}

ret_t TVgcanvas::Ellipse(float_t x, float_t y, float_t rx, float_t ry) {
  return vgcanvas_ellipse(((vgcanvas_t*)(this->nativeObj)), x, y, rx, ry);
}

ret_t TVgcanvas::ClosePath() {
  return vgcanvas_close_path(((vgcanvas_t*)(this->nativeObj)));
}

ret_t TVgcanvas::PathWinding(bool dir) {
  return vgcanvas_path_winding(((vgcanvas_t*)(this->nativeObj)), dir);
}

ret_t TVgcanvas::Rotate(float_t rad) {
  return vgcanvas_rotate(((vgcanvas_t*)(this->nativeObj)), rad);
}

ret_t TVgcanvas::Scale(float_t x, float_t y) {
  return vgcanvas_scale(((vgcanvas_t*)(this->nativeObj)), x, y);
}

ret_t TVgcanvas::Translate(float_t x, float_t y) {
  return vgcanvas_translate(((vgcanvas_t*)(this->nativeObj)), x, y);
}

ret_t TVgcanvas::Transform(float_t a, float_t b, float_t c, float_t d, float_t e, float_t f) {
  return vgcanvas_transform(((vgcanvas_t*)(this->nativeObj)), a, b, c, d, e, f);
}

ret_t TVgcanvas::SetTransform(float_t a, float_t b, float_t c, float_t d, float_t e, float_t f) {
  return vgcanvas_set_transform(((vgcanvas_t*)(this->nativeObj)), a, b, c, d, e, f);
}

ret_t TVgcanvas::ClipPath() {
  return vgcanvas_clip_path(((vgcanvas_t*)(this->nativeObj)));
}

ret_t TVgcanvas::ClipRect(float_t x, float_t y, float_t w, float_t h) {
  return vgcanvas_clip_rect(((vgcanvas_t*)(this->nativeObj)), x, y, w, h);
}

ret_t TVgcanvas::IntersectClipRect(float_t x, float_t y, float_t w, float_t h) {
  return vgcanvas_intersect_clip_rect(((vgcanvas_t*)(this->nativeObj)), x, y, w, h);
}

ret_t TVgcanvas::Fill() {
  return vgcanvas_fill(((vgcanvas_t*)(this->nativeObj)));
}

ret_t TVgcanvas::Stroke() {
  return vgcanvas_stroke(((vgcanvas_t*)(this->nativeObj)));
}

ret_t TVgcanvas::Paint(bool stroke, TBitmap& img) {
  return vgcanvas_paint(((vgcanvas_t*)(this->nativeObj)), stroke, ((bitmap_t*)(img.nativeObj)));
}

ret_t TVgcanvas::SetFont(char* font) {
  return vgcanvas_set_font(((vgcanvas_t*)(this->nativeObj)), font);
}

ret_t TVgcanvas::SetFontSize(float_t font) {
  return vgcanvas_set_font_size(((vgcanvas_t*)(this->nativeObj)), font);
}

ret_t TVgcanvas::SetTextAlign(char* value) {
  return vgcanvas_set_text_align(((vgcanvas_t*)(this->nativeObj)), value);
}

ret_t TVgcanvas::SetTextBaseline(char* value) {
  return vgcanvas_set_text_baseline(((vgcanvas_t*)(this->nativeObj)), value);
}

ret_t TVgcanvas::FillText(char* text, float_t x, float_t y, float_t max_width) {
  return vgcanvas_fill_text(((vgcanvas_t*)(this->nativeObj)), text, x, y, max_width);
}

float_t TVgcanvas::MeasureText(char* text) {
  return vgcanvas_measure_text(((vgcanvas_t*)(this->nativeObj)), text);
}

ret_t TVgcanvas::DrawImage(TBitmap& img, float_t sx, float_t sy, float_t sw, float_t sh, float_t dx,
                           float_t dy, float_t dw, float_t dh) {
  return vgcanvas_draw_image(((vgcanvas_t*)(this->nativeObj)), ((bitmap_t*)(img.nativeObj)), sx, sy,
                             sw, sh, dx, dy, dw, dh);
}

ret_t TVgcanvas::DrawIcon(TBitmap& img, float_t sx, float_t sy, float_t sw, float_t sh, float_t dx,
                          float_t dy, float_t dw, float_t dh) {
  return vgcanvas_draw_icon(((vgcanvas_t*)(this->nativeObj)), ((bitmap_t*)(img.nativeObj)), sx, sy,
                            sw, sh, dx, dy, dw, dh);
}

ret_t TVgcanvas::SetAntialias(bool value) {
  return vgcanvas_set_antialias(((vgcanvas_t*)(this->nativeObj)), value);
}

ret_t TVgcanvas::SetGlobalAlpha(float_t alpha) {
  return vgcanvas_set_global_alpha(((vgcanvas_t*)(this->nativeObj)), alpha);
}

ret_t TVgcanvas::SetLineWidth(float_t value) {
  return vgcanvas_set_line_width(((vgcanvas_t*)(this->nativeObj)), value);
}

ret_t TVgcanvas::SetFillColor(const char* color) {
  return vgcanvas_set_fill_color_str(((vgcanvas_t*)(this->nativeObj)), color);
}

ret_t TVgcanvas::SetStrokeColor(const char* color) {
  return vgcanvas_set_stroke_color_str(((vgcanvas_t*)(this->nativeObj)), color);
}

ret_t TVgcanvas::SetLineCap(char* value) {
  return vgcanvas_set_line_cap(((vgcanvas_t*)(this->nativeObj)), value);
}

ret_t TVgcanvas::SetLineJoin(char* value) {
  return vgcanvas_set_line_join(((vgcanvas_t*)(this->nativeObj)), value);
}

ret_t TVgcanvas::SetMiterLimit(float_t value) {
  return vgcanvas_set_miter_limit(((vgcanvas_t*)(this->nativeObj)), value);
}

ret_t TVgcanvas::Save() {
  return vgcanvas_save(((vgcanvas_t*)(this->nativeObj)));
}

ret_t TVgcanvas::Restore() {
  return vgcanvas_restore(((vgcanvas_t*)(this->nativeObj)));
}

wh_t TVgcanvas::GetW() const {
  return ((vgcanvas_t*)(this->nativeObj))->w;
}

wh_t TVgcanvas::GetH() const {
  return ((vgcanvas_t*)(this->nativeObj))->h;
}

uint32_t TVgcanvas::GetStride() const {
  return ((vgcanvas_t*)(this->nativeObj))->stride;
}

float_t TVgcanvas::GetRatio() const {
  return ((vgcanvas_t*)(this->nativeObj))->ratio;
}

bool TVgcanvas::GetAntiAlias() const {
  return ((vgcanvas_t*)(this->nativeObj))->anti_alias;
}

float_t TVgcanvas::GetLineWidth() const {
  return ((vgcanvas_t*)(this->nativeObj))->line_width;
}

float_t TVgcanvas::GetGlobalAlpha() const {
  return ((vgcanvas_t*)(this->nativeObj))->global_alpha;
}

float_t TVgcanvas::GetMiterLimit() const {
  return ((vgcanvas_t*)(this->nativeObj))->miter_limit;
}

const char* TVgcanvas::GetLineCap() const {
  return ((vgcanvas_t*)(this->nativeObj))->line_cap;
}

const char* TVgcanvas::GetLineJoin() const {
  return ((vgcanvas_t*)(this->nativeObj))->line_join;
}

char* TVgcanvas::GetFont() const {
  return ((vgcanvas_t*)(this->nativeObj))->font;
}

float_t TVgcanvas::GetFontSize() const {
  return ((vgcanvas_t*)(this->nativeObj))->font_size;
}

const char* TVgcanvas::GetTextAlign() const {
  return ((vgcanvas_t*)(this->nativeObj))->text_align;
}

const char* TVgcanvas::GetTextBaseline() const {
  return ((vgcanvas_t*)(this->nativeObj))->text_baseline;
}

int32_t TWidget::CountChildren() {
  return widget_count_children(((widget_t*)(this->nativeObj)));
}

TWidget TWidget::GetChild(int32_t index) {
  return TWidget((widget_t*)(widget_get_child(((widget_t*)(this->nativeObj)), index)));
}

TWidget TWidget::GetFocusedWidget() {
  return TWidget((widget_t*)(widget_get_focused_widget(((widget_t*)(this->nativeObj)))));
}

TNativeWindow TWidget::GetNativeWindow() {
  return TNativeWindow((emitter_t*)(widget_get_native_window(((widget_t*)(this->nativeObj)))));
}

int32_t TWidget::IndexOf() {
  return widget_index_of(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::CloseWindow() {
  return widget_close_window(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::Back() {
  return widget_back(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::BackToHome() {
  return widget_back_to_home(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::Move(xy_t x, xy_t y) {
  return widget_move(((widget_t*)(this->nativeObj)), x, y);
}

ret_t TWidget::Resize(wh_t w, wh_t h) {
  return widget_resize(((widget_t*)(this->nativeObj)), w, h);
}

ret_t TWidget::MoveResize(xy_t x, xy_t y, wh_t w, wh_t h) {
  return widget_move_resize(((widget_t*)(this->nativeObj)), x, y, w, h);
}

ret_t TWidget::SetValue(int32_t value) {
  return widget_set_value(((widget_t*)(this->nativeObj)), value);
}

ret_t TWidget::AnimateValueTo(int32_t value, uint32_t duration) {
  return widget_animate_value_to(((widget_t*)(this->nativeObj)), value, duration);
}

ret_t TWidget::AddValue(int32_t delta) {
  return widget_add_value(((widget_t*)(this->nativeObj)), delta);
}

bool TWidget::IsStyleExist(const char* style_name, const char* state_name) {
  return widget_is_style_exist(((widget_t*)(this->nativeObj)), style_name, state_name);
}

ret_t TWidget::UseStyle(const char* style) {
  return widget_use_style(((widget_t*)(this->nativeObj)), style);
}

ret_t TWidget::SetText(const char* text) {
  return widget_set_text_utf8(((widget_t*)(this->nativeObj)), text);
}

ret_t TWidget::SetChildText(const char* name, const char* text) {
  return widget_set_child_text_utf8(((widget_t*)(this->nativeObj)), name, text);
}

ret_t TWidget::SetChildTextWithDouble(const char* name, const char* format, double value) {
  return widget_set_child_text_with_double(((widget_t*)(this->nativeObj)), name, format, value);
}

ret_t TWidget::SetChildTextWithInt(const char* name, const char* format, int value) {
  return widget_set_child_text_with_int(((widget_t*)(this->nativeObj)), name, format, value);
}

ret_t TWidget::SetTrText(const char* text) {
  return widget_set_tr_text(((widget_t*)(this->nativeObj)), text);
}

int32_t TWidget::GetValue() {
  return widget_get_value(((widget_t*)(this->nativeObj)));
}

bool TWidget::GetEnable() {
  return widget_get_enable(((widget_t*)(this->nativeObj)));
}

bool TWidget::GetFloating() {
  return widget_get_floating(((widget_t*)(this->nativeObj)));
}

bool TWidget::GetAutoAdjustSize() {
  return widget_get_auto_adjust_size(((widget_t*)(this->nativeObj)));
}

bool TWidget::GetWithFocusState() {
  return widget_get_with_focus_state(((widget_t*)(this->nativeObj)));
}

bool TWidget::GetFocusable() {
  return widget_get_focusable(((widget_t*)(this->nativeObj)));
}

bool TWidget::GetSensitive() {
  return widget_get_sensitive(((widget_t*)(this->nativeObj)));
}

bool TWidget::GetVisible() {
  return widget_get_visible(((widget_t*)(this->nativeObj)));
}

bool TWidget::GetFeedback() {
  return widget_get_feedback(((widget_t*)(this->nativeObj)));
}

const wchar_t* TWidget::GetText() {
  return widget_get_text(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::SetName(const char* name) {
  return widget_set_name(((widget_t*)(this->nativeObj)), name);
}

ret_t TWidget::SetTheme(const char* name) {
  return widget_set_theme(((widget_t*)(this->nativeObj)), name);
}

ret_t TWidget::SetPointerCursor(const char* cursor) {
  return widget_set_pointer_cursor(((widget_t*)(this->nativeObj)), cursor);
}

ret_t TWidget::SetAnimation(const char* animation) {
  return widget_set_animation(((widget_t*)(this->nativeObj)), animation);
}

ret_t TWidget::CreateAnimator(const char* animation) {
  return widget_create_animator(((widget_t*)(this->nativeObj)), animation);
}

ret_t TWidget::StartAnimator(const char* name) {
  return widget_start_animator(((widget_t*)(this->nativeObj)), name);
}

ret_t TWidget::SetAnimatorTimeScale(const char* name, float_t time_scale) {
  return widget_set_animator_time_scale(((widget_t*)(this->nativeObj)), name, time_scale);
}

ret_t TWidget::PauseAnimator(const char* name) {
  return widget_pause_animator(((widget_t*)(this->nativeObj)), name);
}

ret_t TWidget::StopAnimator(const char* name) {
  return widget_stop_animator(((widget_t*)(this->nativeObj)), name);
}

ret_t TWidget::DestroyAnimator(const char* name) {
  return widget_destroy_animator(((widget_t*)(this->nativeObj)), name);
}

ret_t TWidget::SetEnable(bool enable) {
  return widget_set_enable(((widget_t*)(this->nativeObj)), enable);
}

ret_t TWidget::SetFeedback(bool feedback) {
  return widget_set_feedback(((widget_t*)(this->nativeObj)), feedback);
}

ret_t TWidget::SetAutoAdjustSize(bool auto_adjust_size) {
  return widget_set_auto_adjust_size(((widget_t*)(this->nativeObj)), auto_adjust_size);
}

ret_t TWidget::SetFloating(bool floating) {
  return widget_set_floating(((widget_t*)(this->nativeObj)), floating);
}

ret_t TWidget::SetFocused(bool focused) {
  return widget_set_focused(((widget_t*)(this->nativeObj)), focused);
}

ret_t TWidget::SetFocusable(bool focusable) {
  return widget_set_focusable(((widget_t*)(this->nativeObj)), focusable);
}

ret_t TWidget::SetState(const char* state) {
  return widget_set_state(((widget_t*)(this->nativeObj)), state);
}

ret_t TWidget::SetOpacity(uint8_t opacity) {
  return widget_set_opacity(((widget_t*)(this->nativeObj)), opacity);
}

ret_t TWidget::SetDirtyRectTolerance(uint16_t dirty_rect_tolerance) {
  return widget_set_dirty_rect_tolerance(((widget_t*)(this->nativeObj)), dirty_rect_tolerance);
}

ret_t TWidget::DestroyChildren() {
  return widget_destroy_children(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::AddChild(TWidget& child) {
  return widget_add_child(((widget_t*)(this->nativeObj)), ((widget_t*)(child.nativeObj)));
}

ret_t TWidget::RemoveChild(TWidget& child) {
  return widget_remove_child(((widget_t*)(this->nativeObj)), ((widget_t*)(child.nativeObj)));
}

ret_t TWidget::InsertChild(uint32_t index, TWidget& child) {
  return widget_insert_child(((widget_t*)(this->nativeObj)), index, ((widget_t*)(child.nativeObj)));
}

ret_t TWidget::Restack(uint32_t index) {
  return widget_restack(((widget_t*)(this->nativeObj)), index);
}

TWidget TWidget::Child(const char* name) {
  return TWidget((widget_t*)(widget_child(((widget_t*)(this->nativeObj)), name)));
}

TWidget TWidget::Lookup(const char* name, bool recursive) {
  return TWidget((widget_t*)(widget_lookup(((widget_t*)(this->nativeObj)), name, recursive)));
}

TWidget TWidget::LookupByType(const char* type, bool recursive) {
  return TWidget(
      (widget_t*)(widget_lookup_by_type(((widget_t*)(this->nativeObj)), type, recursive)));
}

ret_t TWidget::SetVisible(bool visible) {
  return widget_set_visible(((widget_t*)(this->nativeObj)), visible);
}

ret_t TWidget::SetVisibleOnly(bool visible) {
  return widget_set_visible_only(((widget_t*)(this->nativeObj)), visible);
}

ret_t TWidget::SetSensitive(bool sensitive) {
  return widget_set_sensitive(((widget_t*)(this->nativeObj)), sensitive);
}

uint32_t TWidget::On(event_type_t type, event_func_t on_event, void* ctx) {
  return widget_on(((widget_t*)(this->nativeObj)), type, on_event, ctx);
}

ret_t TWidget::Off(uint32_t id) {
  return widget_off(((widget_t*)(this->nativeObj)), id);
}

ret_t TWidget::InvalidateForce(TRect& r) {
  return widget_invalidate_force(((widget_t*)(this->nativeObj)), ((const rect_t*)(r.nativeObj)));
}

ret_t TWidget::SetPropStr(const char* name, const char* v) {
  return widget_set_prop_str(((widget_t*)(this->nativeObj)), name, v);
}

const char* TWidget::GetPropStr(const char* name, const char* defval) {
  return widget_get_prop_str(((widget_t*)(this->nativeObj)), name, defval);
}

ret_t TWidget::SetPropPointer(const char* name, void* v) {
  return widget_set_prop_pointer(((widget_t*)(this->nativeObj)), name, v);
}

void* TWidget::GetPropPointer(const char* name) {
  return widget_get_prop_pointer(((widget_t*)(this->nativeObj)), name);
}

ret_t TWidget::SetPropInt(const char* name, int32_t v) {
  return widget_set_prop_int(((widget_t*)(this->nativeObj)), name, v);
}

int32_t TWidget::GetPropInt(const char* name, int32_t defval) {
  return widget_get_prop_int(((widget_t*)(this->nativeObj)), name, defval);
}

ret_t TWidget::SetPropBool(const char* name, bool v) {
  return widget_set_prop_bool(((widget_t*)(this->nativeObj)), name, v);
}

bool TWidget::GetPropBool(const char* name, bool defval) {
  return widget_get_prop_bool(((widget_t*)(this->nativeObj)), name, defval);
}

bool TWidget::IsWindowOpened() {
  return widget_is_window_opened(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsWindowCreated() {
  return widget_is_window_created(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsParentOf(TWidget& child) {
  return widget_is_parent_of(((widget_t*)(this->nativeObj)), ((widget_t*)(child.nativeObj)));
}

bool TWidget::IsDirectParentOf(TWidget& child) {
  return widget_is_direct_parent_of(((widget_t*)(this->nativeObj)), ((widget_t*)(child.nativeObj)));
}

bool TWidget::IsWindow() {
  return widget_is_window(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsSystemBar() {
  return widget_is_system_bar(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsNormalWindow() {
  return widget_is_normal_window(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsDialog() {
  return widget_is_dialog(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsPopup() {
  return widget_is_popup(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsOverlay() {
  return widget_is_overlay(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsOpenedDialog() {
  return widget_is_opened_dialog(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsOpenedPopup() {
  return widget_is_opened_popup(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsKeyboard() {
  return widget_is_keyboard(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsDesigningWindow() {
  return widget_is_designing_window(((widget_t*)(this->nativeObj)));
}

bool TWidget::IsWindowManager() {
  return widget_is_window_manager(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::Foreach(tk_visit_t visit, void* ctx) {
  return widget_foreach(((widget_t*)(this->nativeObj)), visit, ctx);
}

TWidget TWidget::GetWindow() {
  return TWidget((widget_t*)(widget_get_window(((widget_t*)(this->nativeObj)))));
}

TWidget TWidget::GetWindowManager() {
  return TWidget((widget_t*)(widget_get_window_manager(((widget_t*)(this->nativeObj)))));
}

const char* TWidget::GetType() {
  return widget_get_type(((widget_t*)(this->nativeObj)));
}

TWidget TWidget::Clone(TWidget& parent) {
  return TWidget(
      (widget_t*)(widget_clone(((widget_t*)(this->nativeObj)), ((widget_t*)(parent.nativeObj)))));
}

bool TWidget::Equal(TWidget& other) {
  return widget_equal(((widget_t*)(this->nativeObj)), ((widget_t*)(other.nativeObj)));
}

ret_t TWidget::Destroy() {
  return widget_destroy(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::DestroyAsync() {
  return widget_destroy_async(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::Unref() {
  return widget_unref(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::StrokeBorderRect(TCanvas& c, TRect& r) {
  return widget_stroke_border_rect(((widget_t*)(this->nativeObj)), ((canvas_t*)(c.nativeObj)),
                                   ((const rect_t*)(r.nativeObj)));
}

ret_t TWidget::FillBgRect(TCanvas& c, TRect& r, image_draw_type_t draw_type) {
  return widget_fill_bg_rect(((widget_t*)(this->nativeObj)), ((canvas_t*)(c.nativeObj)),
                             ((const rect_t*)(r.nativeObj)), draw_type);
}

ret_t TWidget::FillFgRect(TCanvas& c, TRect& r, image_draw_type_t draw_type) {
  return widget_fill_fg_rect(((widget_t*)(this->nativeObj)), ((canvas_t*)(c.nativeObj)),
                             ((const rect_t*)(r.nativeObj)), draw_type);
}

ret_t TWidget::DispatchToTarget(TEvent& e) {
  return widget_dispatch_to_target(((widget_t*)(this->nativeObj)), ((event_t*)(e.nativeObj)));
}

ret_t TWidget::DispatchToKeyTarget(TEvent& e) {
  return widget_dispatch_to_key_target(((widget_t*)(this->nativeObj)), ((event_t*)(e.nativeObj)));
}

const char* TWidget::GetStyleType() {
  return widget_get_style_type(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::UpdateStyle() {
  return widget_update_style(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::UpdateStyleRecursive() {
  return widget_update_style_recursive(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::SetAsKeyTarget() {
  return widget_set_as_key_target(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::FocusNext() {
  return widget_focus_next(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::FocusPrev() {
  return widget_focus_prev(((widget_t*)(this->nativeObj)));
}

const char* TWidget::GetStateForStyle(bool active, bool checked) {
  return widget_get_state_for_style(((widget_t*)(this->nativeObj)), active, checked);
}

ret_t TWidget::Layout() {
  return widget_layout(((widget_t*)(this->nativeObj)));
}

ret_t TWidget::SetSelfLayout(const char* params) {
  return widget_set_self_layout(((widget_t*)(this->nativeObj)), params);
}

ret_t TWidget::SetChildrenLayout(const char* params) {
  return widget_set_children_layout(((widget_t*)(this->nativeObj)), params);
}

ret_t TWidget::SetSelfLayoutParams(const char* x, const char* y, const char* w, const char* h) {
  return widget_set_self_layout_params(((widget_t*)(this->nativeObj)), x, y, w, h);
}

ret_t TWidget::SetStyleInt(const char* state_and_name, int32_t value) {
  return widget_set_style_int(((widget_t*)(this->nativeObj)), state_and_name, value);
}

ret_t TWidget::SetStyleStr(const char* state_and_name, const char* value) {
  return widget_set_style_str(((widget_t*)(this->nativeObj)), state_and_name, value);
}

ret_t TWidget::SetStyleColor(const char* state_and_name, uint32_t value) {
  return widget_set_style_color(((widget_t*)(this->nativeObj)), state_and_name, value);
}

xy_t TWidget::GetX() const {
  return ((widget_t*)(this->nativeObj))->x;
}

xy_t TWidget::GetY() const {
  return ((widget_t*)(this->nativeObj))->y;
}

wh_t TWidget::GetW() const {
  return ((widget_t*)(this->nativeObj))->w;
}

wh_t TWidget::GetH() const {
  return ((widget_t*)(this->nativeObj))->h;
}

char* TWidget::GetName() const {
  return ((widget_t*)(this->nativeObj))->name;
}

char* TWidget::GetPointerCursor() const {
  return ((widget_t*)(this->nativeObj))->pointer_cursor;
}

char* TWidget::GetTrText() const {
  return ((widget_t*)(this->nativeObj))->tr_text;
}

char* TWidget::GetStyle() const {
  return ((widget_t*)(this->nativeObj))->style;
}

char* TWidget::GetAnimation() const {
  return ((widget_t*)(this->nativeObj))->animation;
}

bool TWidget::GetEnable() const {
  return ((widget_t*)(this->nativeObj))->enable;
}

bool TWidget::GetFeedback() const {
  return ((widget_t*)(this->nativeObj))->feedback;
}

bool TWidget::GetVisible() const {
  return ((widget_t*)(this->nativeObj))->visible;
}

bool TWidget::GetSensitive() const {
  return ((widget_t*)(this->nativeObj))->sensitive;
}

bool TWidget::GetFocusable() const {
  return ((widget_t*)(this->nativeObj))->focusable;
}

bool TWidget::GetWithFocusState() const {
  return ((widget_t*)(this->nativeObj))->with_focus_state;
}

bool TWidget::GetAutoAdjustSize() const {
  return ((widget_t*)(this->nativeObj))->auto_adjust_size;
}

bool TWidget::GetFloating() const {
  return ((widget_t*)(this->nativeObj))->floating;
}

uint16_t TWidget::GetDirtyRectTolerance() const {
  return ((widget_t*)(this->nativeObj))->dirty_rect_tolerance;
}

TWidget TWidget::GetParent() const {
  return TWidget(((widget_t*)(this->nativeObj))->parent);
}

ret_t TAppConf::Save() {
  return app_conf_save();
}

ret_t TAppConf::Reload() {
  return app_conf_reload();
}

ret_t TAppConf::Deinit() {
  return app_conf_deinit();
}

bool TAppConf::Exist(const char* key) {
  return app_conf_exist(key);
}

ret_t TAppConf::SetInt(const char* key, int32_t v) {
  return app_conf_set_int(key, v);
}

ret_t TAppConf::SetInt64(const char* key, int64_t v) {
  return app_conf_set_int64(key, v);
}

ret_t TAppConf::SetBool(const char* key, bool v) {
  return app_conf_set_bool(key, v);
}

ret_t TAppConf::SetDouble(const char* key, double v) {
  return app_conf_set_double(key, v);
}

ret_t TAppConf::SetStr(const char* key, const char* v) {
  return app_conf_set_str(key, v);
}

int32_t TAppConf::GetInt(const char* key, int32_t defval) {
  return app_conf_get_int(key, defval);
}

int64_t TAppConf::GetInt64(const char* key, int64_t defval) {
  return app_conf_get_int64(key, defval);
}

bool TAppConf::GetBool(const char* key, bool defval) {
  return app_conf_get_bool(key, defval);
}

double TAppConf::GetDouble(const char* key, double defval) {
  return app_conf_get_double(key, defval);
}

const char* TAppConf::GetStr(const char* key, const char* defval) {
  return app_conf_get_str(key, defval);
}

ret_t TAppConf::Remove(const char* key) {
  return app_conf_remove(key);
}

uint16_t TAssetInfo::GetType() {
  return asset_info_get_type(((asset_info_t*)(this->nativeObj)));
}

const char* TAssetInfo::GetName() {
  return asset_info_get_name(((asset_info_t*)(this->nativeObj)));
}

uint16_t TAssetInfo::GetType() const {
  return ((asset_info_t*)(this->nativeObj))->type;
}

uint8_t TAssetInfo::GetSubtype() const {
  return ((asset_info_t*)(this->nativeObj))->subtype;
}

uint8_t TAssetInfo::GetIsInRom() const {
  return ((asset_info_t*)(this->nativeObj))->is_in_rom;
}

uint32_t TAssetInfo::GetSize() const {
  return ((asset_info_t*)(this->nativeObj))->size;
}

uint32_t TAssetInfo::GetRefcount() const {
  return ((asset_info_t*)(this->nativeObj))->refcount;
}

char* TAssetInfo::GetName() const {
  return ((asset_info_t*)(this->nativeObj))->name;
}

TColor TColor::Create(uint8_t r, uint8_t b, uint8_t g, uint8_t a) {
  return TColor((color_t*)(color_create(r, b, g, a)));
}

TColor TColor::FromStr(const char* str) {
  return TColor((color_t*)(color_from_str(((color_t*)(this->nativeObj)), str)));
}

uint8_t TColor::R() {
  return color_r(((color_t*)(this->nativeObj)));
}

uint8_t TColor::G() {
  return color_g(((color_t*)(this->nativeObj)));
}

uint8_t TColor::B() {
  return color_b(((color_t*)(this->nativeObj)));
}

uint8_t TColor::A() {
  return color_a(((color_t*)(this->nativeObj)));
}

uint32_t TColor::GetColor() {
  return color_get_color(((color_t*)(this->nativeObj)));
}

ret_t TColor::Destroy() {
  return color_destroy(((color_t*)(this->nativeObj)));
}

uint32_t TColor::GetColor() const {
  return ((color_t*)(this->nativeObj))->color;
}

TDateTime TDateTime::Create() {
  return TDateTime((date_time_t*)(date_time_create()));
}

ret_t TDateTime::SetYear(uint32_t year) {
  return date_time_set_year(((date_time_t*)(this->nativeObj)), year);
}

ret_t TDateTime::SetMonth(uint32_t month) {
  return date_time_set_month(((date_time_t*)(this->nativeObj)), month);
}

ret_t TDateTime::SetDay(uint32_t day) {
  return date_time_set_day(((date_time_t*)(this->nativeObj)), day);
}

ret_t TDateTime::SetHour(uint32_t hour) {
  return date_time_set_hour(((date_time_t*)(this->nativeObj)), hour);
}

ret_t TDateTime::SetMinute(uint32_t minute) {
  return date_time_set_minute(((date_time_t*)(this->nativeObj)), minute);
}

ret_t TDateTime::SetSecond(uint32_t second) {
  return date_time_set_second(((date_time_t*)(this->nativeObj)), second);
}

ret_t TDateTime::Set() {
  return date_time_set(((date_time_t*)(this->nativeObj)));
}

ret_t TDateTime::FromTime(uint64_t time) {
  return date_time_from_time(((date_time_t*)(this->nativeObj)), time);
}

uint64_t TDateTime::ToTime() {
  return date_time_to_time(((date_time_t*)(this->nativeObj)));
}

ret_t TDateTime::AddDelta(int64_t delta) {
  return date_time_add_delta(((date_time_t*)(this->nativeObj)), delta);
}

bool TDateTime::IsLeap(uint32_t year) {
  return date_time_is_leap(year);
}

int32_t TDateTime::GetDays(uint32_t year, uint32_t montn) {
  return date_time_get_days(year, montn);
}

int32_t TDateTime::GetWday(uint32_t year, uint32_t montn, uint32_t day) {
  return date_time_get_wday(year, montn, day);
}

const char* TDateTime::GetMonthName(uint32_t montn) {
  return date_time_get_month_name(montn);
}

const char* TDateTime::GetWdayName(uint32_t wday) {
  return date_time_get_wday_name(wday);
}

ret_t TDateTime::Destroy() {
  return date_time_destroy(((date_time_t*)(this->nativeObj)));
}

int32_t TDateTime::GetSecond() const {
  return ((date_time_t*)(this->nativeObj))->second;
}

int32_t TDateTime::GetMinute() const {
  return ((date_time_t*)(this->nativeObj))->minute;
}

int32_t TDateTime::GetHour() const {
  return ((date_time_t*)(this->nativeObj))->hour;
}

int32_t TDateTime::GetDay() const {
  return ((date_time_t*)(this->nativeObj))->day;
}

int32_t TDateTime::GetWday() const {
  return ((date_time_t*)(this->nativeObj))->wday;
}

int32_t TDateTime::GetMonth() const {
  return ((date_time_t*)(this->nativeObj))->month;
}

int32_t TDateTime::GetYear() const {
  return ((date_time_t*)(this->nativeObj))->year;
}

TNamedValue TNamedValue::Create() {
  return TNamedValue((named_value_t*)(named_value_create()));
}

ret_t TNamedValue::SetName(const char* name) {
  return named_value_set_name(((named_value_t*)(this->nativeObj)), name);
}

ret_t TNamedValue::SetValue(TValue& value) {
  return named_value_set_value(((named_value_t*)(this->nativeObj)),
                               ((const value_t*)(value.nativeObj)));
}

TValue TNamedValue::GetValue() {
  return TValue((value_t*)(named_value_get_value(((named_value_t*)(this->nativeObj)))));
}

ret_t TNamedValue::Destroy() {
  return named_value_destroy(((named_value_t*)(this->nativeObj)));
}

char* TNamedValue::GetName() const {
  return ((named_value_t*)(this->nativeObj))->name;
}

TRlog TRlog::Create(const char* filename_pattern, uint32_t max_size, uint32_t buff_size) {
  return TRlog((rlog_t*)(rlog_create(filename_pattern, max_size, buff_size)));
}

ret_t TRlog::Write(const char* str) {
  return rlog_write(((rlog_t*)(this->nativeObj)), str);
}

uint64_t TTimeNow::S() {
  return time_now_s();
}

uint64_t TTimeNow::Ms() {
  return time_now_ms();
}

uint64_t TTimeNow::Us() {
  return time_now_us();
}

TAssetsManager TAssetsManager::Instance() {
  return TAssetsManager((emitter_t*)(assets_manager()));
}

ret_t TAssetsManager::SetTheme(const char* theme) {
  return assets_manager_set_theme(((assets_manager_t*)(this->nativeObj)), theme);
}

TAssetInfo TAssetsManager::Ref(asset_type_t type, char* name) {
  return TAssetInfo(
      (asset_info_t*)(assets_manager_ref(((assets_manager_t*)(this->nativeObj)), type, name)));
}

TAssetInfo TAssetsManager::RefEx(asset_type_t type, uint16_t subtype, char* name) {
  return TAssetInfo((asset_info_t*)(assets_manager_ref_ex(((assets_manager_t*)(this->nativeObj)),
                                                          type, subtype, name)));
}

ret_t TAssetsManager::Unref(TAssetInfo& info) {
  return assets_manager_unref(((assets_manager_t*)(this->nativeObj)),
                              ((asset_info_t*)(info.nativeObj)));
}

int32_t TWheelEvent::GetDy() const {
  return ((wheel_event_t*)(this->nativeObj))->dy;
}

bool TWheelEvent::GetAlt() const {
  return ((wheel_event_t*)(this->nativeObj))->alt;
}

bool TWheelEvent::GetCtrl() const {
  return ((wheel_event_t*)(this->nativeObj))->ctrl;
}

bool TWheelEvent::GetShift() const {
  return ((wheel_event_t*)(this->nativeObj))->shift;
}

int32_t TOrientationEvent::GetOrientation() const {
  return ((orientation_event_t*)(this->nativeObj))->orientation;
}

xy_t TPointerEvent::GetX() const {
  return ((pointer_event_t*)(this->nativeObj))->x;
}

xy_t TPointerEvent::GetY() const {
  return ((pointer_event_t*)(this->nativeObj))->y;
}

uint8_t TPointerEvent::GetButton() const {
  return ((pointer_event_t*)(this->nativeObj))->button;
}

bool TPointerEvent::GetPressed() const {
  return ((pointer_event_t*)(this->nativeObj))->pressed;
}

bool TPointerEvent::GetAlt() const {
  return ((pointer_event_t*)(this->nativeObj))->alt;
}

bool TPointerEvent::GetCtrl() const {
  return ((pointer_event_t*)(this->nativeObj))->ctrl;
}

bool TPointerEvent::GetCmd() const {
  return ((pointer_event_t*)(this->nativeObj))->cmd;
}

bool TPointerEvent::GetMenu() const {
  return ((pointer_event_t*)(this->nativeObj))->menu;
}

bool TPointerEvent::GetShift() const {
  return ((pointer_event_t*)(this->nativeObj))->shift;
}

uint32_t TKeyEvent::GetKey() const {
  return ((key_event_t*)(this->nativeObj))->key;
}

bool TKeyEvent::GetAlt() const {
  return ((key_event_t*)(this->nativeObj))->alt;
}

bool TKeyEvent::GetLalt() const {
  return ((key_event_t*)(this->nativeObj))->lalt;
}

bool TKeyEvent::GetRalt() const {
  return ((key_event_t*)(this->nativeObj))->ralt;
}

bool TKeyEvent::GetCtrl() const {
  return ((key_event_t*)(this->nativeObj))->ctrl;
}

bool TKeyEvent::GetLctrl() const {
  return ((key_event_t*)(this->nativeObj))->lctrl;
}

bool TKeyEvent::GetRctrl() const {
  return ((key_event_t*)(this->nativeObj))->rctrl;
}

bool TKeyEvent::GetShift() const {
  return ((key_event_t*)(this->nativeObj))->shift;
}

bool TKeyEvent::GetLshift() const {
  return ((key_event_t*)(this->nativeObj))->lshift;
}

bool TKeyEvent::GetRshift() const {
  return ((key_event_t*)(this->nativeObj))->rshift;
}

bool TKeyEvent::GetCmd() const {
  return ((key_event_t*)(this->nativeObj))->cmd;
}

bool TKeyEvent::GetMenu() const {
  return ((key_event_t*)(this->nativeObj))->menu;
}

bool TKeyEvent::GetCapslock() const {
  return ((key_event_t*)(this->nativeObj))->capslock;
}

TCanvas TPaintEvent::GetC() const {
  return TCanvas(((paint_event_t*)(this->nativeObj))->c);
}

TWidget TWindowEvent::GetWindow() const {
  return TWidget(((window_event_t*)(this->nativeObj))->window);
}

xy_t TMultiGestureEvent::GetX() const {
  return ((multi_gesture_event_t*)(this->nativeObj))->x;
}

xy_t TMultiGestureEvent::GetY() const {
  return ((multi_gesture_event_t*)(this->nativeObj))->y;
}

float TMultiGestureEvent::GetRotation() const {
  return ((multi_gesture_event_t*)(this->nativeObj))->rotation;
}

float TMultiGestureEvent::GetDistance() const {
  return ((multi_gesture_event_t*)(this->nativeObj))->distance;
}

ret_t TImageBase::SetImage(char* name) {
  return image_base_set_image(((widget_t*)(this->nativeObj)), name);
}

ret_t TImageBase::SetRotation(float_t rotation) {
  return image_base_set_rotation(((widget_t*)(this->nativeObj)), rotation);
}

ret_t TImageBase::SetScale(float_t scale_x, float_t scale_y) {
  return image_base_set_scale(((widget_t*)(this->nativeObj)), scale_x, scale_y);
}

ret_t TImageBase::SetAnchor(float_t anchor_x, float_t anchor_y) {
  return image_base_set_anchor(((widget_t*)(this->nativeObj)), anchor_x, anchor_y);
}

ret_t TImageBase::SetSelected(bool selected) {
  return image_base_set_selected(((widget_t*)(this->nativeObj)), selected);
}

ret_t TImageBase::SetSelectable(bool selectable) {
  return image_base_set_selectable(((widget_t*)(this->nativeObj)), selectable);
}

ret_t TImageBase::SetClickable(bool clickable) {
  return image_base_set_clickable(((widget_t*)(this->nativeObj)), clickable);
}

char* TImageBase::GetImage() const {
  return ((image_base_t*)(this->nativeObj))->image;
}

float_t TImageBase::GetAnchorX() const {
  return ((image_base_t*)(this->nativeObj))->anchor_x;
}

float_t TImageBase::GetAnchorY() const {
  return ((image_base_t*)(this->nativeObj))->anchor_y;
}

float_t TImageBase::GetScaleX() const {
  return ((image_base_t*)(this->nativeObj))->scale_x;
}

float_t TImageBase::GetScaleY() const {
  return ((image_base_t*)(this->nativeObj))->scale_y;
}

float_t TImageBase::GetRotation() const {
  return ((image_base_t*)(this->nativeObj))->rotation;
}

bool TImageBase::GetClickable() const {
  return ((image_base_t*)(this->nativeObj))->clickable;
}

bool TImageBase::GetSelectable() const {
  return ((image_base_t*)(this->nativeObj))->selectable;
}

bool TImageBase::GetSelected() const {
  return ((image_base_t*)(this->nativeObj))->selected;
}

ret_t TStyleMutable::SetName(const char* name) {
  return style_mutable_set_name(((style_t*)(this->nativeObj)), name);
}

ret_t TStyleMutable::SetInt(const char* state, const char* name, uint32_t val) {
  return style_mutable_set_int(((style_t*)(this->nativeObj)), state, name, val);
}

TStyle TStyleMutable::Create(TStyle& default_style) {
  return TStyleMutable((style_t*)(style_mutable_create(((style_t*)(default_style.nativeObj)))));
}

char* TStyleMutable::GetName() const {
  return ((style_mutable_t*)(this->nativeObj))->name;
}

char* TWindowBase::GetTheme() const {
  return ((window_base_t*)(this->nativeObj))->theme;
}

uint16_t TWindowBase::GetDesignW() const {
  return ((window_base_t*)(this->nativeObj))->design_w;
}

uint16_t TWindowBase::GetDesignH() const {
  return ((window_base_t*)(this->nativeObj))->design_h;
}

bool TWindowBase::GetAutoScaleChildrenX() const {
  return ((window_base_t*)(this->nativeObj))->auto_scale_children_x;
}

bool TWindowBase::GetAutoScaleChildrenY() const {
  return ((window_base_t*)(this->nativeObj))->auto_scale_children_y;
}

bool TWindowBase::GetAutoScaleChildrenW() const {
  return ((window_base_t*)(this->nativeObj))->auto_scale_children_w;
}

bool TWindowBase::GetAutoScaleChildrenH() const {
  return ((window_base_t*)(this->nativeObj))->auto_scale_children_h;
}

bool TWindowBase::GetDisableAnim() const {
  return ((window_base_t*)(this->nativeObj))->disable_anim;
}

window_closable_t TWindowBase::GetClosable() const {
  return ((window_base_t*)(this->nativeObj))->closable;
}

char* TWindowBase::GetOpenAnimHint() const {
  return ((window_base_t*)(this->nativeObj))->open_anim_hint;
}

char* TWindowBase::GetCloseAnimHint() const {
  return ((window_base_t*)(this->nativeObj))->close_anim_hint;
}

char* TWindowBase::GetMoveFocusPrevKey() const {
  return ((window_base_t*)(this->nativeObj))->move_focus_prev_key;
}

char* TWindowBase::GetMoveFocusNextKey() const {
  return ((window_base_t*)(this->nativeObj))->move_focus_next_key;
}

char* TWindowBase::GetMoveFocusUpKey() const {
  return ((window_base_t*)(this->nativeObj))->move_focus_up_key;
}

char* TWindowBase::GetMoveFocusDownKey() const {
  return ((window_base_t*)(this->nativeObj))->move_focus_down_key;
}

char* TWindowBase::GetMoveFocusLeftKey() const {
  return ((window_base_t*)(this->nativeObj))->move_focus_left_key;
}

char* TWindowBase::GetMoveFocusRightKey() const {
  return ((window_base_t*)(this->nativeObj))->move_focus_right_key;
}

bool TWindowBase::GetSingleInstance() const {
  return ((window_base_t*)(this->nativeObj))->single_instance;
}

bool TWindowBase::GetStronglyFocus() const {
  return ((window_base_t*)(this->nativeObj))->strongly_focus;
}

TWidget TWindowManager::GetTopMainWindow() {
  return TWidget((widget_t*)(window_manager_get_top_main_window(((widget_t*)(this->nativeObj)))));
}

TWidget TWindowManager::GetTopWindow() {
  return TWidget((widget_t*)(window_manager_get_top_window(((widget_t*)(this->nativeObj)))));
}

TWidget TWindowManager::GetPrevWindow() {
  return TWidget((widget_t*)(window_manager_get_prev_window(((widget_t*)(this->nativeObj)))));
}

xy_t TWindowManager::GetPointerX() {
  return window_manager_get_pointer_x(((widget_t*)(this->nativeObj)));
}

xy_t TWindowManager::GetPointerY() {
  return window_manager_get_pointer_y(((widget_t*)(this->nativeObj)));
}

bool TWindowManager::GetPointerPressed() {
  return window_manager_get_pointer_pressed(((widget_t*)(this->nativeObj)));
}

bool TWindowManager::IsAnimating() {
  return window_manager_is_animating(((widget_t*)(this->nativeObj)));
}

ret_t TWindowManager::SetShowFps(bool show_fps) {
  return window_manager_set_show_fps(((widget_t*)(this->nativeObj)), show_fps);
}

ret_t TWindowManager::SetMaxFps(uint32_t max_fps) {
  return window_manager_set_max_fps(((widget_t*)(this->nativeObj)), max_fps);
}

ret_t TWindowManager::SetIgnoreInputEvents(bool ignore_input_events) {
  return window_manager_set_ignore_input_events(((widget_t*)(this->nativeObj)),
                                                ignore_input_events);
}

ret_t TWindowManager::SetScreenSaverTime(uint32_t screen_saver_time) {
  return window_manager_set_screen_saver_time(((widget_t*)(this->nativeObj)), screen_saver_time);
}

ret_t TWindowManager::SetCursor(const char* cursor) {
  return window_manager_set_cursor(((widget_t*)(this->nativeObj)), cursor);
}

ret_t TWindowManager::Back() {
  return window_manager_back(((widget_t*)(this->nativeObj)));
}

ret_t TWindowManager::BackToHome() {
  return window_manager_back_to_home(((widget_t*)(this->nativeObj)));
}

ret_t TWindowManager::BackTo(const char* target) {
  return window_manager_back_to(((widget_t*)(this->nativeObj)), target);
}

ret_t TWindowManager::Resize(wh_t w, wh_t h) {
  return window_manager_resize(((widget_t*)(this->nativeObj)), w, h);
}

ret_t TWindowManager::CloseAll() {
  return window_manager_close_all(((widget_t*)(this->nativeObj)));
}

TWidget TCanvasWidget::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TCanvasWidget(
      (widget_t*)(canvas_widget_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TColorPicker::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TColorPicker(
      (widget_t*)(color_picker_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TColorPicker::SetColor(const char* color) {
  return color_picker_set_color(((widget_t*)(this->nativeObj)), color);
}

const char* TColorPicker::GetValue() const {
  return ((color_picker_t*)(this->nativeObj))->value;
}

TWidget TDraggable::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TDraggable((widget_t*)(draggable_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TDraggable::SetTop(int32_t top) {
  return draggable_set_top(((widget_t*)(this->nativeObj)), top);
}

ret_t TDraggable::SetBottom(int32_t bottom) {
  return draggable_set_bottom(((widget_t*)(this->nativeObj)), bottom);
}

ret_t TDraggable::SetLeft(int32_t left) {
  return draggable_set_left(((widget_t*)(this->nativeObj)), left);
}

ret_t TDraggable::SetRight(int32_t right) {
  return draggable_set_right(((widget_t*)(this->nativeObj)), right);
}

ret_t TDraggable::SetVerticalOnly(bool vertical_only) {
  return draggable_set_vertical_only(((widget_t*)(this->nativeObj)), vertical_only);
}

ret_t TDraggable::SetHorizontalOnly(bool horizontal_only) {
  return draggable_set_horizontal_only(((widget_t*)(this->nativeObj)), horizontal_only);
}

ret_t TDraggable::SetDragWindow(bool drag_window) {
  return draggable_set_drag_window(((widget_t*)(this->nativeObj)), drag_window);
}

int32_t TDraggable::GetTop() const {
  return ((draggable_t*)(this->nativeObj))->top;
}

int32_t TDraggable::GetBottom() const {
  return ((draggable_t*)(this->nativeObj))->bottom;
}

int32_t TDraggable::GetLeft() const {
  return ((draggable_t*)(this->nativeObj))->left;
}

int32_t TDraggable::GetRight() const {
  return ((draggable_t*)(this->nativeObj))->right;
}

bool TDraggable::GetVerticalOnly() const {
  return ((draggable_t*)(this->nativeObj))->vertical_only;
}

bool TDraggable::GetHorizontalOnly() const {
  return ((draggable_t*)(this->nativeObj))->horizontal_only;
}

bool TDraggable::GetDragWindow() const {
  return ((draggable_t*)(this->nativeObj))->drag_window;
}

TWidget TFileBrowserView::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TFileBrowserView(
      (widget_t*)(file_browser_view_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TFileBrowserView::SetInitDir(const char* init_dir) {
  return file_browser_view_set_init_dir(((widget_t*)(this->nativeObj)), init_dir);
}

ret_t TFileBrowserView::SetTopDir(const char* top_dir) {
  return file_browser_view_set_top_dir(((widget_t*)(this->nativeObj)), top_dir);
}

ret_t TFileBrowserView::SetFilter(const char* filter) {
  return file_browser_view_set_filter(((widget_t*)(this->nativeObj)), filter);
}

ret_t TFileBrowserView::Reload() {
  return file_browser_view_reload(((widget_t*)(this->nativeObj)));
}

ret_t TFileBrowserView::SetIgnoreHiddenFiles(bool ignore_hidden_files) {
  return file_browser_view_set_ignore_hidden_files(((widget_t*)(this->nativeObj)),
                                                   ignore_hidden_files);
}

ret_t TFileBrowserView::SetSortAscending(bool sort_ascending) {
  return file_browser_view_set_sort_ascending(((widget_t*)(this->nativeObj)), sort_ascending);
}

ret_t TFileBrowserView::SetShowCheckButton(bool show_check_button) {
  return file_browser_view_set_show_check_button(((widget_t*)(this->nativeObj)), show_check_button);
}

ret_t TFileBrowserView::SetSortBy(const char* sort_by) {
  return file_browser_view_set_sort_by(((widget_t*)(this->nativeObj)), sort_by);
}

const char* TFileBrowserView::GetCwd() {
  return file_browser_view_get_cwd(((widget_t*)(this->nativeObj)));
}

ret_t TFileBrowserView::CreateDir(const char* name) {
  return file_browser_view_create_dir(((widget_t*)(this->nativeObj)), name);
}

ret_t TFileBrowserView::CreateFile(const char* name, const char* data, uint32_t size) {
  return file_browser_view_create_file(((widget_t*)(this->nativeObj)), name, data, size);
}

char* TFileBrowserView::GetInitDir() const {
  return ((file_browser_view_t*)(this->nativeObj))->init_dir;
}

char* TFileBrowserView::GetTopDir() const {
  return ((file_browser_view_t*)(this->nativeObj))->top_dir;
}

char* TFileBrowserView::GetFilter() const {
  return ((file_browser_view_t*)(this->nativeObj))->filter;
}

bool TFileBrowserView::GetIgnoreHiddenFiles() const {
  return ((file_browser_view_t*)(this->nativeObj))->ignore_hidden_files;
}

bool TFileBrowserView::GetSortAscending() const {
  return ((file_browser_view_t*)(this->nativeObj))->sort_ascending;
}

bool TFileBrowserView::GetShowCheckButton() const {
  return ((file_browser_view_t*)(this->nativeObj))->show_check_button;
}

char* TFileBrowserView::GetSortBy() const {
  return ((file_browser_view_t*)(this->nativeObj))->sort_by;
}

TFileChooser TFileChooser::Create() {
  return TFileChooser((emitter_t*)(file_chooser_create()));
}

ret_t TFileChooser::SetInitDir(const char* init_dir) {
  return file_chooser_set_init_dir(((file_chooser_t*)(this->nativeObj)), init_dir);
}

ret_t TFileChooser::SetTopDir(const char* top_dir) {
  return file_chooser_set_top_dir(((file_chooser_t*)(this->nativeObj)), top_dir);
}

ret_t TFileChooser::SetFilter(const char* filter) {
  return file_chooser_set_filter(((file_chooser_t*)(this->nativeObj)), filter);
}

ret_t TFileChooser::ChooseFileForSave() {
  return file_chooser_choose_file_for_save(((file_chooser_t*)(this->nativeObj)));
}

ret_t TFileChooser::ChooseFileForOpen() {
  return file_chooser_choose_file_for_open(((file_chooser_t*)(this->nativeObj)));
}

ret_t TFileChooser::ChooseFolder() {
  return file_chooser_choose_folder(((file_chooser_t*)(this->nativeObj)));
}

const char* TFileChooser::GetDir() {
  return file_chooser_get_dir(((file_chooser_t*)(this->nativeObj)));
}

const char* TFileChooser::GetFilename() {
  return file_chooser_get_filename(((file_chooser_t*)(this->nativeObj)));
}

bool TFileChooser::IsAborted() {
  return file_chooser_is_aborted(((file_chooser_t*)(this->nativeObj)));
}

TWidget TGaugePointer::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TGaugePointer(
      (widget_t*)(gauge_pointer_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TGaugePointer::SetAngle(float_t angle) {
  return gauge_pointer_set_angle(((widget_t*)(this->nativeObj)), angle);
}

ret_t TGaugePointer::SetImage(const char* image) {
  return gauge_pointer_set_image(((widget_t*)(this->nativeObj)), image);
}

ret_t TGaugePointer::SetAnchor(const char* anchor_x, const char* anchor_y) {
  return gauge_pointer_set_anchor(((widget_t*)(this->nativeObj)), anchor_x, anchor_y);
}

float_t TGaugePointer::GetAngle() const {
  return ((gauge_pointer_t*)(this->nativeObj))->angle;
}

char* TGaugePointer::GetImage() const {
  return ((gauge_pointer_t*)(this->nativeObj))->image;
}

char* TGaugePointer::GetAnchorX() const {
  return ((gauge_pointer_t*)(this->nativeObj))->anchor_x;
}

char* TGaugePointer::GetAnchorY() const {
  return ((gauge_pointer_t*)(this->nativeObj))->anchor_y;
}

TWidget TGauge::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TGauge((widget_t*)(gauge_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TGauge::SetImage(char* name) {
  return gauge_set_image(((widget_t*)(this->nativeObj)), name);
}

ret_t TGauge::SetDrawType(image_draw_type_t draw_type) {
  return gauge_set_draw_type(((widget_t*)(this->nativeObj)), draw_type);
}

char* TGauge::GetImage() const {
  return ((gauge_t*)(this->nativeObj))->image;
}

image_draw_type_t TGauge::GetDrawType() const {
  return ((gauge_t*)(this->nativeObj))->draw_type;
}

TWidget TImageAnimation::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TImageAnimation(
      (widget_t*)(image_animation_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TImageAnimation::SetLoop(bool loop) {
  return image_animation_set_loop(((widget_t*)(this->nativeObj)), loop);
}

ret_t TImageAnimation::SetImage(const char* image) {
  return image_animation_set_image(((widget_t*)(this->nativeObj)), image);
}

ret_t TImageAnimation::SetInterval(uint32_t interval) {
  return image_animation_set_interval(((widget_t*)(this->nativeObj)), interval);
}

ret_t TImageAnimation::SetDelay(uint32_t delay) {
  return image_animation_set_delay(((widget_t*)(this->nativeObj)), delay);
}

ret_t TImageAnimation::SetAutoPlay(bool auto_play) {
  return image_animation_set_auto_play(((widget_t*)(this->nativeObj)), auto_play);
}

ret_t TImageAnimation::SetSequence(const char* sequence) {
  return image_animation_set_sequence(((widget_t*)(this->nativeObj)), sequence);
}

ret_t TImageAnimation::SetRangeSequence(uint32_t start_index, uint32_t end_index) {
  return image_animation_set_range_sequence(((widget_t*)(this->nativeObj)), start_index, end_index);
}

ret_t TImageAnimation::Play() {
  return image_animation_play(((widget_t*)(this->nativeObj)));
}

ret_t TImageAnimation::Stop() {
  return image_animation_stop(((widget_t*)(this->nativeObj)));
}

ret_t TImageAnimation::Pause() {
  return image_animation_pause(((widget_t*)(this->nativeObj)));
}

ret_t TImageAnimation::Next() {
  return image_animation_next(((widget_t*)(this->nativeObj)));
}

ret_t TImageAnimation::SetFormat(const char* format) {
  return image_animation_set_format(((widget_t*)(this->nativeObj)), format);
}

ret_t TImageAnimation::SetUnloadAfterPaint(bool unload_after_paint) {
  return image_animation_set_unload_after_paint(((widget_t*)(this->nativeObj)), unload_after_paint);
}

ret_t TImageAnimation::SetReverse(bool reverse) {
  return image_animation_set_reverse(((widget_t*)(this->nativeObj)), reverse);
}

ret_t TImageAnimation::SetShowWhenDone(bool show_when_done) {
  return image_animation_set_show_when_done(((widget_t*)(this->nativeObj)), show_when_done);
}

bool TImageAnimation::IsPlaying() {
  return image_animation_is_playing(((widget_t*)(this->nativeObj)));
}

char* TImageAnimation::GetImage() const {
  return ((image_animation_t*)(this->nativeObj))->image;
}

char* TImageAnimation::GetSequence() const {
  return ((image_animation_t*)(this->nativeObj))->sequence;
}

uint32_t TImageAnimation::GetStartIndex() const {
  return ((image_animation_t*)(this->nativeObj))->start_index;
}

uint32_t TImageAnimation::GetEndIndex() const {
  return ((image_animation_t*)(this->nativeObj))->end_index;
}

bool TImageAnimation::GetReverse() const {
  return ((image_animation_t*)(this->nativeObj))->reverse;
}

bool TImageAnimation::GetLoop() const {
  return ((image_animation_t*)(this->nativeObj))->loop;
}

bool TImageAnimation::GetAutoPlay() const {
  return ((image_animation_t*)(this->nativeObj))->auto_play;
}

bool TImageAnimation::GetUnloadAfterPaint() const {
  return ((image_animation_t*)(this->nativeObj))->unload_after_paint;
}

char* TImageAnimation::GetFormat() const {
  return ((image_animation_t*)(this->nativeObj))->format;
}

uint32_t TImageAnimation::GetInterval() const {
  return ((image_animation_t*)(this->nativeObj))->interval;
}

uint32_t TImageAnimation::GetDelay() const {
  return ((image_animation_t*)(this->nativeObj))->delay;
}

bool TImageAnimation::GetShowWhenDone() const {
  return ((image_animation_t*)(this->nativeObj))->show_when_done;
}

TWidget TImageValue::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TImageValue((widget_t*)(image_value_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TImageValue::SetImage(const char* image) {
  return image_value_set_image(((widget_t*)(this->nativeObj)), image);
}

ret_t TImageValue::SetFormat(const char* format) {
  return image_value_set_format(((widget_t*)(this->nativeObj)), format);
}

ret_t TImageValue::SetClickAddDelta(double delta) {
  return image_value_set_click_add_delta(((widget_t*)(this->nativeObj)), delta);
}

ret_t TImageValue::SetValue(double value) {
  return image_value_set_value(((widget_t*)(this->nativeObj)), value);
}

ret_t TImageValue::SetMin(double min) {
  return image_value_set_min(((widget_t*)(this->nativeObj)), min);
}

ret_t TImageValue::SetMax(double max) {
  return image_value_set_max(((widget_t*)(this->nativeObj)), max);
}

char* TImageValue::GetImage() const {
  return ((image_value_t*)(this->nativeObj))->image;
}

char* TImageValue::GetFormat() const {
  return ((image_value_t*)(this->nativeObj))->format;
}

double TImageValue::GetClickAddDelta() const {
  return ((image_value_t*)(this->nativeObj))->click_add_delta;
}

double TImageValue::GetValue() const {
  return ((image_value_t*)(this->nativeObj))->value;
}

double TImageValue::GetMin() const {
  return ((image_value_t*)(this->nativeObj))->min;
}

double TImageValue::GetMax() const {
  return ((image_value_t*)(this->nativeObj))->max;
}

ret_t TCandidates::SetPre(bool pre) {
  return candidates_set_pre(((widget_t*)(this->nativeObj)), pre);
}

ret_t TCandidates::SetSelectByNum(bool select_by_num) {
  return candidates_set_select_by_num(((widget_t*)(this->nativeObj)), select_by_num);
}

ret_t TCandidates::SetAutoHide(bool auto_hide) {
  return candidates_set_auto_hide(((widget_t*)(this->nativeObj)), auto_hide);
}

ret_t TCandidates::SetButtonStyle(const char* button_style) {
  return candidates_set_button_style(((widget_t*)(this->nativeObj)), button_style);
}

bool TCandidates::GetPre() const {
  return ((candidates_t*)(this->nativeObj))->pre;
}

bool TCandidates::GetSelectByNum() const {
  return ((candidates_t*)(this->nativeObj))->select_by_num;
}

bool TCandidates::GetAutoHide() const {
  return ((candidates_t*)(this->nativeObj))->auto_hide;
}

char* TCandidates::GetButtonStyle() const {
  return ((candidates_t*)(this->nativeObj))->button_style;
}

TWidget TLangIndicator::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TLangIndicator(
      (widget_t*)(lang_indicator_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TLangIndicator::SetImage(const char* image) {
  return lang_indicator_set_image(((widget_t*)(this->nativeObj)), image);
}

char* TLangIndicator::GetImage() const {
  return ((lang_indicator_t*)(this->nativeObj))->image;
}

TWidget TLineNumber::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TLineNumber((widget_t*)(line_number_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TLineNumber::SetTopMargin(int32_t top_margin) {
  return line_number_set_top_margin(((widget_t*)(this->nativeObj)), top_margin);
}

ret_t TLineNumber::SetBottomMargin(int32_t bottom_margin) {
  return line_number_set_bottom_margin(((widget_t*)(this->nativeObj)), bottom_margin);
}

ret_t TLineNumber::SetLineHeight(int32_t line_height) {
  return line_number_set_line_height(((widget_t*)(this->nativeObj)), line_height);
}

ret_t TLineNumber::SetYoffset(int32_t yoffset) {
  return line_number_set_yoffset(((widget_t*)(this->nativeObj)), yoffset);
}

TWidget TMledit::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TMledit((widget_t*)(mledit_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TMledit::SetReadonly(bool readonly) {
  return mledit_set_readonly(((widget_t*)(this->nativeObj)), readonly);
}

ret_t TMledit::SetCancelable(bool cancelable) {
  return mledit_set_cancelable(((widget_t*)(this->nativeObj)), cancelable);
}

ret_t TMledit::SetFocus(bool focus) {
  return mledit_set_focus(((widget_t*)(this->nativeObj)), focus);
}

ret_t TMledit::SetWrapWord(bool wrap_word) {
  return mledit_set_wrap_word(((widget_t*)(this->nativeObj)), wrap_word);
}

ret_t TMledit::SetMaxLines(uint32_t max_lines) {
  return mledit_set_max_lines(((widget_t*)(this->nativeObj)), max_lines);
}

ret_t TMledit::SetMaxChars(uint32_t max_chars) {
  return mledit_set_max_chars(((widget_t*)(this->nativeObj)), max_chars);
}

ret_t TMledit::SetTips(char* tips) {
  return mledit_set_tips(((widget_t*)(this->nativeObj)), tips);
}

ret_t TMledit::SetTrTips(const char* tr_tips) {
  return mledit_set_tr_tips(((widget_t*)(this->nativeObj)), tr_tips);
}

ret_t TMledit::SetKeyboard(char* keyboard) {
  return mledit_set_keyboard(((widget_t*)(this->nativeObj)), keyboard);
}

ret_t TMledit::SetCursor(uint32_t cursor) {
  return mledit_set_cursor(((widget_t*)(this->nativeObj)), cursor);
}

uint32_t TMledit::GetCursor() {
  return mledit_get_cursor(((widget_t*)(this->nativeObj)));
}

ret_t TMledit::SetScrollLine(uint32_t scroll_line) {
  return mledit_set_scroll_line(((widget_t*)(this->nativeObj)), scroll_line);
}

ret_t TMledit::ScrollToOffset(uint32_t offset) {
  return mledit_scroll_to_offset(((widget_t*)(this->nativeObj)), offset);
}

ret_t TMledit::SetOpenImWhenFocused(bool open_im_when_focused) {
  return mledit_set_open_im_when_focused(((widget_t*)(this->nativeObj)), open_im_when_focused);
}

ret_t TMledit::SetCloseImWhenBlured(bool close_im_when_blured) {
  return mledit_set_close_im_when_blured(((widget_t*)(this->nativeObj)), close_im_when_blured);
}

ret_t TMledit::SetSelect(uint32_t start, uint32_t end) {
  return mledit_set_select(((widget_t*)(this->nativeObj)), start, end);
}

char* TMledit::GetSelectedText() {
  return mledit_get_selected_text(((widget_t*)(this->nativeObj)));
}

char* TMledit::GetTips() const {
  return ((mledit_t*)(this->nativeObj))->tips;
}

char* TMledit::GetTrTips() const {
  return ((mledit_t*)(this->nativeObj))->tr_tips;
}

char* TMledit::GetKeyboard() const {
  return ((mledit_t*)(this->nativeObj))->keyboard;
}

uint32_t TMledit::GetMaxLines() const {
  return ((mledit_t*)(this->nativeObj))->max_lines;
}

uint32_t TMledit::GetMaxChars() const {
  return ((mledit_t*)(this->nativeObj))->max_chars;
}

bool TMledit::GetWrapWord() const {
  return ((mledit_t*)(this->nativeObj))->wrap_word;
}

uint32_t TMledit::GetScrollLine() const {
  return ((mledit_t*)(this->nativeObj))->scroll_line;
}

bool TMledit::GetReadonly() const {
  return ((mledit_t*)(this->nativeObj))->readonly;
}

bool TMledit::GetCancelable() const {
  return ((mledit_t*)(this->nativeObj))->cancelable;
}

bool TMledit::GetOpenImWhenFocused() const {
  return ((mledit_t*)(this->nativeObj))->open_im_when_focused;
}

bool TMledit::GetCloseImWhenBlured() const {
  return ((mledit_t*)(this->nativeObj))->close_im_when_blured;
}

TWidget TProgressCircle::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TProgressCircle(
      (widget_t*)(progress_circle_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TProgressCircle::SetValue(float_t value) {
  return progress_circle_set_value(((widget_t*)(this->nativeObj)), value);
}

ret_t TProgressCircle::SetMax(uint32_t max) {
  return progress_circle_set_max(((widget_t*)(this->nativeObj)), max);
}

ret_t TProgressCircle::SetFormat(const char* format) {
  return progress_circle_set_format(((widget_t*)(this->nativeObj)), format);
}

ret_t TProgressCircle::SetLineWidth(uint32_t line_width) {
  return progress_circle_set_line_width(((widget_t*)(this->nativeObj)), line_width);
}

ret_t TProgressCircle::SetStartAngle(int32_t start_angle) {
  return progress_circle_set_start_angle(((widget_t*)(this->nativeObj)), start_angle);
}

ret_t TProgressCircle::SetLineCap(const char* line_cap) {
  return progress_circle_set_line_cap(((widget_t*)(this->nativeObj)), line_cap);
}

ret_t TProgressCircle::SetShowText(bool show_text) {
  return progress_circle_set_show_text(((widget_t*)(this->nativeObj)), show_text);
}

ret_t TProgressCircle::SetCounterClockWise(bool counter_clock_wise) {
  return progress_circle_set_counter_clock_wise(((widget_t*)(this->nativeObj)), counter_clock_wise);
}

float_t TProgressCircle::GetValue() const {
  return ((progress_circle_t*)(this->nativeObj))->value;
}

float_t TProgressCircle::GetMax() const {
  return ((progress_circle_t*)(this->nativeObj))->max;
}

char* TProgressCircle::GetFormat() const {
  return ((progress_circle_t*)(this->nativeObj))->format;
}

int32_t TProgressCircle::GetStartAngle() const {
  return ((progress_circle_t*)(this->nativeObj))->start_angle;
}

uint32_t TProgressCircle::GetLineWidth() const {
  return ((progress_circle_t*)(this->nativeObj))->line_width;
}

char* TProgressCircle::GetLineCap() const {
  return ((progress_circle_t*)(this->nativeObj))->line_cap;
}

bool TProgressCircle::GetCounterClockWise() const {
  return ((progress_circle_t*)(this->nativeObj))->counter_clock_wise;
}

bool TProgressCircle::GetShowText() const {
  return ((progress_circle_t*)(this->nativeObj))->show_text;
}

TWidget TRichTextView::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TRichTextView(
      (widget_t*)(rich_text_view_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TRichText::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TRichText((widget_t*)(rich_text_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TRichText::SetText(char* text) {
  return rich_text_set_text(((widget_t*)(this->nativeObj)), text);
}

ret_t TRichText::SetYslidable(bool yslidable) {
  return rich_text_set_yslidable(((widget_t*)(this->nativeObj)), yslidable);
}

uint32_t TRichText::GetLineGap() const {
  return ((rich_text_t*)(this->nativeObj))->line_gap;
}

bool TRichText::GetYslidable() const {
  return ((rich_text_t*)(this->nativeObj))->yslidable;
}

TWidget THscrollLabel::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return THscrollLabel(
      (widget_t*)(hscroll_label_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t THscrollLabel::SetLull(int32_t lull) {
  return hscroll_label_set_lull(((widget_t*)(this->nativeObj)), lull);
}

ret_t THscrollLabel::SetDuration(int32_t duration) {
  return hscroll_label_set_duration(((widget_t*)(this->nativeObj)), duration);
}

ret_t THscrollLabel::SetOnlyFocus(bool only_focus) {
  return hscroll_label_set_only_focus(((widget_t*)(this->nativeObj)), only_focus);
}

ret_t THscrollLabel::SetOnlyParentFocus(bool only_parent_focus) {
  return hscroll_label_set_only_parent_focus(((widget_t*)(this->nativeObj)), only_parent_focus);
}

ret_t THscrollLabel::SetLoop(bool loop) {
  return hscroll_label_set_loop(((widget_t*)(this->nativeObj)), loop);
}

ret_t THscrollLabel::SetYoyo(bool yoyo) {
  return hscroll_label_set_yoyo(((widget_t*)(this->nativeObj)), yoyo);
}

ret_t THscrollLabel::SetEllipses(bool ellipses) {
  return hscroll_label_set_ellipses(((widget_t*)(this->nativeObj)), ellipses);
}

ret_t THscrollLabel::SetXoffset(int32_t xoffset) {
  return hscroll_label_set_xoffset(((widget_t*)(this->nativeObj)), xoffset);
}

ret_t THscrollLabel::Start() {
  return hscroll_label_start(((widget_t*)(this->nativeObj)));
}

ret_t THscrollLabel::Stop() {
  return hscroll_label_stop(((widget_t*)(this->nativeObj)));
}

bool THscrollLabel::GetOnlyFocus() const {
  return ((hscroll_label_t*)(this->nativeObj))->only_focus;
}

bool THscrollLabel::GetOnlyParentFocus() const {
  return ((hscroll_label_t*)(this->nativeObj))->only_parent_focus;
}

bool THscrollLabel::GetLoop() const {
  return ((hscroll_label_t*)(this->nativeObj))->loop;
}

bool THscrollLabel::GetYoyo() const {
  return ((hscroll_label_t*)(this->nativeObj))->yoyo;
}

bool THscrollLabel::GetEllipses() const {
  return ((hscroll_label_t*)(this->nativeObj))->ellipses;
}

int32_t THscrollLabel::GetLull() const {
  return ((hscroll_label_t*)(this->nativeObj))->lull;
}

int32_t THscrollLabel::GetDuration() const {
  return ((hscroll_label_t*)(this->nativeObj))->duration;
}

int32_t THscrollLabel::GetXoffset() const {
  return ((hscroll_label_t*)(this->nativeObj))->xoffset;
}

int32_t THscrollLabel::GetTextW() const {
  return ((hscroll_label_t*)(this->nativeObj))->text_w;
}

TWidget TListItem::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TListItem((widget_t*)(list_item_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TListViewH::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TListViewH((widget_t*)(list_view_h_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TListViewH::SetItemWidth(int32_t item_width) {
  return list_view_h_set_item_width(((widget_t*)(this->nativeObj)), item_width);
}

ret_t TListViewH::SetSpacing(int32_t spacing) {
  return list_view_h_set_spacing(((widget_t*)(this->nativeObj)), spacing);
}

int32_t TListViewH::GetItemWidth() const {
  return ((list_view_h_t*)(this->nativeObj))->item_width;
}

int32_t TListViewH::GetSpacing() const {
  return ((list_view_h_t*)(this->nativeObj))->spacing;
}

TWidget TListView::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TListView((widget_t*)(list_view_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TListView::SetItemHeight(int32_t item_height) {
  return list_view_set_item_height(((widget_t*)(this->nativeObj)), item_height);
}

ret_t TListView::SetDefaultItemHeight(int32_t default_item_height) {
  return list_view_set_default_item_height(((widget_t*)(this->nativeObj)), default_item_height);
}

ret_t TListView::SetAutoHideScrollBar(bool auto_hide_scroll_bar) {
  return list_view_set_auto_hide_scroll_bar(((widget_t*)(this->nativeObj)), auto_hide_scroll_bar);
}

ret_t TListView::SetFloatingScrollBar(bool floating_scroll_bar) {
  return list_view_set_floating_scroll_bar(((widget_t*)(this->nativeObj)), floating_scroll_bar);
}

ret_t TListView::Reinit() {
  return list_view_reinit(((widget_t*)(this->nativeObj)));
}

int32_t TListView::GetItemHeight() const {
  return ((list_view_t*)(this->nativeObj))->item_height;
}

int32_t TListView::GetDefaultItemHeight() const {
  return ((list_view_t*)(this->nativeObj))->default_item_height;
}

bool TListView::GetAutoHideScrollBar() const {
  return ((list_view_t*)(this->nativeObj))->auto_hide_scroll_bar;
}

bool TListView::GetFloatingScrollBar() const {
  return ((list_view_t*)(this->nativeObj))->floating_scroll_bar;
}

TWidget TScrollBar::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TScrollBar((widget_t*)(scroll_bar_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TScrollBar::CreateMobile(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TScrollBar(
      (widget_t*)(scroll_bar_create_mobile(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TScrollBar::CreateDesktop(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TScrollBar(
      (widget_t*)(scroll_bar_create_desktop(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TScrollBar::SetParams(int32_t virtual_size, int32_t row) {
  return scroll_bar_set_params(((widget_t*)(this->nativeObj)), virtual_size, row);
}

ret_t TScrollBar::ScrollTo(int32_t value, int32_t duration) {
  return scroll_bar_scroll_to(((widget_t*)(this->nativeObj)), value, duration);
}

ret_t TScrollBar::SetValue(int32_t value) {
  return scroll_bar_set_value(((widget_t*)(this->nativeObj)), value);
}

ret_t TScrollBar::AddDelta(int32_t delta) {
  return scroll_bar_add_delta(((widget_t*)(this->nativeObj)), delta);
}

ret_t TScrollBar::ScrollDelta(int32_t delta) {
  return scroll_bar_scroll_delta(((widget_t*)(this->nativeObj)), delta);
}

ret_t TScrollBar::SetValueOnly(int32_t value) {
  return scroll_bar_set_value_only(((widget_t*)(this->nativeObj)), value);
}

ret_t TScrollBar::SetAutoHide(bool auto_hide) {
  return scroll_bar_set_auto_hide(((widget_t*)(this->nativeObj)), auto_hide);
}

bool TScrollBar::IsMobile() {
  return scroll_bar_is_mobile(((widget_t*)(this->nativeObj)));
}

int32_t TScrollBar::GetVirtualSize() const {
  return ((scroll_bar_t*)(this->nativeObj))->virtual_size;
}

int32_t TScrollBar::GetValue() const {
  return ((scroll_bar_t*)(this->nativeObj))->value;
}

int32_t TScrollBar::GetRow() const {
  return ((scroll_bar_t*)(this->nativeObj))->row;
}

bool TScrollBar::GetAnimatable() const {
  return ((scroll_bar_t*)(this->nativeObj))->animatable;
}

bool TScrollBar::GetAutoHide() const {
  return ((scroll_bar_t*)(this->nativeObj))->auto_hide;
}

TWidget TScrollView::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TScrollView((widget_t*)(scroll_view_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TScrollView::SetVirtualW(wh_t w) {
  return scroll_view_set_virtual_w(((widget_t*)(this->nativeObj)), w);
}

ret_t TScrollView::SetVirtualH(wh_t h) {
  return scroll_view_set_virtual_h(((widget_t*)(this->nativeObj)), h);
}

ret_t TScrollView::SetXslidable(bool xslidable) {
  return scroll_view_set_xslidable(((widget_t*)(this->nativeObj)), xslidable);
}

ret_t TScrollView::SetYslidable(bool yslidable) {
  return scroll_view_set_yslidable(((widget_t*)(this->nativeObj)), yslidable);
}

ret_t TScrollView::SetSnapToPage(bool snap_to_page) {
  return scroll_view_set_snap_to_page(((widget_t*)(this->nativeObj)), snap_to_page);
}

ret_t TScrollView::SetMoveToPage(bool move_to_page) {
  return scroll_view_set_move_to_page(((widget_t*)(this->nativeObj)), move_to_page);
}

ret_t TScrollView::SetRecursive(bool recursive) {
  return scroll_view_set_recursive(((widget_t*)(this->nativeObj)), recursive);
}

ret_t TScrollView::SetRecursiveOnly(bool recursive) {
  return scroll_view_set_recursive_only(((widget_t*)(this->nativeObj)), recursive);
}

ret_t TScrollView::SetOffset(int32_t xoffset, int32_t yoffset) {
  return scroll_view_set_offset(((widget_t*)(this->nativeObj)), xoffset, yoffset);
}

ret_t TScrollView::SetSpeedScale(float_t xspeed_scale, float_t yspeed_scale) {
  return scroll_view_set_speed_scale(((widget_t*)(this->nativeObj)), xspeed_scale, yspeed_scale);
}

ret_t TScrollView::ScrollTo(int32_t xoffset_end, int32_t yoffset_end, int32_t duration) {
  return scroll_view_scroll_to(((widget_t*)(this->nativeObj)), xoffset_end, yoffset_end, duration);
}

ret_t TScrollView::ScrollDeltaTo(int32_t xoffset_delta, int32_t yoffset_delta, int32_t duration) {
  return scroll_view_scroll_delta_to(((widget_t*)(this->nativeObj)), xoffset_delta, yoffset_delta,
                                     duration);
}

wh_t TScrollView::GetVirtualW() const {
  return ((scroll_view_t*)(this->nativeObj))->virtual_w;
}

wh_t TScrollView::GetVirtualH() const {
  return ((scroll_view_t*)(this->nativeObj))->virtual_h;
}

int32_t TScrollView::GetXoffset() const {
  return ((scroll_view_t*)(this->nativeObj))->xoffset;
}

int32_t TScrollView::GetYoffset() const {
  return ((scroll_view_t*)(this->nativeObj))->yoffset;
}

float_t TScrollView::GetXspeedScale() const {
  return ((scroll_view_t*)(this->nativeObj))->xspeed_scale;
}

float_t TScrollView::GetYspeedScale() const {
  return ((scroll_view_t*)(this->nativeObj))->yspeed_scale;
}

bool TScrollView::GetXslidable() const {
  return ((scroll_view_t*)(this->nativeObj))->xslidable;
}

bool TScrollView::GetYslidable() const {
  return ((scroll_view_t*)(this->nativeObj))->yslidable;
}

bool TScrollView::GetSnapToPage() const {
  return ((scroll_view_t*)(this->nativeObj))->snap_to_page;
}

bool TScrollView::GetMoveToPage() const {
  return ((scroll_view_t*)(this->nativeObj))->move_to_page;
}

bool TScrollView::GetRecursive() const {
  return ((scroll_view_t*)(this->nativeObj))->recursive;
}

TWidget TSlideMenu::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TSlideMenu((widget_t*)(slide_menu_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TSlideMenu::SetValue(uint32_t value) {
  return slide_menu_set_value(((widget_t*)(this->nativeObj)), value);
}

ret_t TSlideMenu::SetAlignV(align_v_t align_v) {
  return slide_menu_set_align_v(((widget_t*)(this->nativeObj)), align_v);
}

ret_t TSlideMenu::SetMinScale(float_t min_scale) {
  return slide_menu_set_min_scale(((widget_t*)(this->nativeObj)), min_scale);
}

int32_t TSlideMenu::GetValue() const {
  return ((slide_menu_t*)(this->nativeObj))->value;
}

align_v_t TSlideMenu::GetAlignV() const {
  return ((slide_menu_t*)(this->nativeObj))->align_v;
}

float_t TSlideMenu::GetMinScale() const {
  return ((slide_menu_t*)(this->nativeObj))->min_scale;
}

TWidget TSlideIndicator::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TSlideIndicator(
      (widget_t*)(slide_indicator_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TSlideIndicator::CreateLinear(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TSlideIndicator(
      (widget_t*)(slide_indicator_create_linear(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TSlideIndicator::CreateArc(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TSlideIndicator(
      (widget_t*)(slide_indicator_create_arc(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TSlideIndicator::SetValue(uint32_t value) {
  return slide_indicator_set_value(((widget_t*)(this->nativeObj)), value);
}

ret_t TSlideIndicator::SetMax(uint32_t max) {
  return slide_indicator_set_max(((widget_t*)(this->nativeObj)), max);
}

ret_t TSlideIndicator::SetDefaultPaint(indicator_default_paint_t default_paint) {
  return slide_indicator_set_default_paint(((widget_t*)(this->nativeObj)), default_paint);
}

ret_t TSlideIndicator::SetAutoHide(uint16_t auto_hide) {
  return slide_indicator_set_auto_hide(((widget_t*)(this->nativeObj)), auto_hide);
}

ret_t TSlideIndicator::SetMargin(int32_t margin) {
  return slide_indicator_set_margin(((widget_t*)(this->nativeObj)), margin);
}

ret_t TSlideIndicator::SetSpacing(float_t spacing) {
  return slide_indicator_set_spacing(((widget_t*)(this->nativeObj)), spacing);
}

ret_t TSlideIndicator::SetSize(uint32_t size) {
  return slide_indicator_set_size(((widget_t*)(this->nativeObj)), size);
}

ret_t TSlideIndicator::SetAnchor(const char* anchor_x, const char* anchor_y) {
  return slide_indicator_set_anchor(((widget_t*)(this->nativeObj)), anchor_x, anchor_y);
}

ret_t TSlideIndicator::SetIndicatedTarget(const char* target_name) {
  return slide_indicator_set_indicated_target(((widget_t*)(this->nativeObj)), target_name);
}

uint32_t TSlideIndicator::GetValue() const {
  return ((slide_indicator_t*)(this->nativeObj))->value;
}

uint32_t TSlideIndicator::GetMax() const {
  return ((slide_indicator_t*)(this->nativeObj))->max;
}

indicator_default_paint_t TSlideIndicator::GetDefaultPaint() const {
  return ((slide_indicator_t*)(this->nativeObj))->default_paint;
}

uint16_t TSlideIndicator::GetAutoHide() const {
  return ((slide_indicator_t*)(this->nativeObj))->auto_hide;
}

int32_t TSlideIndicator::GetMargin() const {
  return ((slide_indicator_t*)(this->nativeObj))->margin;
}

float_t TSlideIndicator::GetSpacing() const {
  return ((slide_indicator_t*)(this->nativeObj))->spacing;
}

uint32_t TSlideIndicator::GetSize() const {
  return ((slide_indicator_t*)(this->nativeObj))->size;
}

float_t TSlideIndicator::GetAnchorX() const {
  return ((slide_indicator_t*)(this->nativeObj))->anchor_x;
}

float_t TSlideIndicator::GetAnchorY() const {
  return ((slide_indicator_t*)(this->nativeObj))->anchor_y;
}

char* TSlideIndicator::GetIndicatedTarget() const {
  return ((slide_indicator_t*)(this->nativeObj))->indicated_target;
}

TWidget TSlideView::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TSlideView((widget_t*)(slide_view_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TSlideView::SetAutoPlay(uint16_t auto_play) {
  return slide_view_set_auto_play(((widget_t*)(this->nativeObj)), auto_play);
}

ret_t TSlideView::SetActive(uint32_t index) {
  return slide_view_set_active(((widget_t*)(this->nativeObj)), index);
}

ret_t TSlideView::SetActiveEx(uint32_t index, bool animate) {
  return slide_view_set_active_ex(((widget_t*)(this->nativeObj)), index, animate);
}

ret_t TSlideView::SetVertical(bool vertical) {
  return slide_view_set_vertical(((widget_t*)(this->nativeObj)), vertical);
}

ret_t TSlideView::SetAnimHint(const char* anim_hint) {
  return slide_view_set_anim_hint(((widget_t*)(this->nativeObj)), anim_hint);
}

ret_t TSlideView::SetLoop(bool loop) {
  return slide_view_set_loop(((widget_t*)(this->nativeObj)), loop);
}

ret_t TSlideView::RemoveIndex(uint32_t index) {
  return slide_view_remove_index(((widget_t*)(this->nativeObj)), index);
}

bool TSlideView::GetVertical() const {
  return ((slide_view_t*)(this->nativeObj))->vertical;
}

uint16_t TSlideView::GetAutoPlay() const {
  return ((slide_view_t*)(this->nativeObj))->auto_play;
}

bool TSlideView::GetLoop() const {
  return ((slide_view_t*)(this->nativeObj))->loop;
}

char* TSlideView::GetAnimHint() const {
  return ((slide_view_t*)(this->nativeObj))->anim_hint;
}

TWidget TSwitch::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TSwitch((widget_t*)(switch_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TSwitch::SetValue(bool value) {
  return switch_set_value(((widget_t*)(this->nativeObj)), value);
}

bool TSwitch::GetValue() const {
  return ((switch_t*)(this->nativeObj))->value;
}

float_t TSwitch::GetMaxXoffsetRatio() const {
  return ((switch_t*)(this->nativeObj))->max_xoffset_ratio;
}

TWidget TTextSelector::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TTextSelector(
      (widget_t*)(text_selector_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TTextSelector::ResetOptions() {
  return text_selector_reset_options(((widget_t*)(this->nativeObj)));
}

int32_t TTextSelector::CountOptions() {
  return text_selector_count_options(((widget_t*)(this->nativeObj)));
}

ret_t TTextSelector::AppendOption(int32_t value, char* text) {
  return text_selector_append_option(((widget_t*)(this->nativeObj)), value, text);
}

ret_t TTextSelector::SetOptions(char* options) {
  return text_selector_set_options(((widget_t*)(this->nativeObj)), options);
}

ret_t TTextSelector::SetRangeOptionsEx(int32_t start, uint32_t nr, int32_t step,
                                       const char* format) {
  return text_selector_set_range_options_ex(((widget_t*)(this->nativeObj)), start, nr, step,
                                            format);
}

ret_t TTextSelector::SetRangeOptions(int32_t start, uint32_t nr, int32_t step) {
  return text_selector_set_range_options(((widget_t*)(this->nativeObj)), start, nr, step);
}

int32_t TTextSelector::GetValue() {
  return text_selector_get_value(((widget_t*)(this->nativeObj)));
}

ret_t TTextSelector::SetValue(int32_t value) {
  return text_selector_set_value(((widget_t*)(this->nativeObj)), value);
}

const char* TTextSelector::GetTextValue() {
  return text_selector_get_text(((widget_t*)(this->nativeObj)));
}

ret_t TTextSelector::SetText(const char* text) {
  return text_selector_set_text(((widget_t*)(this->nativeObj)), text);
}

ret_t TTextSelector::SetSelectedIndex(uint32_t index) {
  return text_selector_set_selected_index(((widget_t*)(this->nativeObj)), index);
}

ret_t TTextSelector::SetVisibleNr(uint32_t visible_nr) {
  return text_selector_set_visible_nr(((widget_t*)(this->nativeObj)), visible_nr);
}

ret_t TTextSelector::SetLocalizeOptions(bool localize_options) {
  return text_selector_set_localize_options(((widget_t*)(this->nativeObj)), localize_options);
}

ret_t TTextSelector::SetLoopOptions(bool loop_options) {
  return text_selector_set_loop_options(((widget_t*)(this->nativeObj)), loop_options);
}

ret_t TTextSelector::SetYspeedScale(float_t yspeed_scale) {
  return text_selector_set_yspeed_scale(((widget_t*)(this->nativeObj)), yspeed_scale);
}

ret_t TTextSelector::SetAnimatingTime(uint32_t animating_time) {
  return text_selector_set_animating_time(((widget_t*)(this->nativeObj)), animating_time);
}

uint32_t TTextSelector::GetVisibleNr() const {
  return ((text_selector_t*)(this->nativeObj))->visible_nr;
}

int32_t TTextSelector::GetSelectedIndex() const {
  return ((text_selector_t*)(this->nativeObj))->selected_index;
}

char* TTextSelector::GetOptions() const {
  return ((text_selector_t*)(this->nativeObj))->options;
}

float_t TTextSelector::GetYspeedScale() const {
  return ((text_selector_t*)(this->nativeObj))->yspeed_scale;
}

uint32_t TTextSelector::GetAnimatingTime() const {
  return ((text_selector_t*)(this->nativeObj))->animating_time;
}

bool TTextSelector::GetLocalizeOptions() const {
  return ((text_selector_t*)(this->nativeObj))->localize_options;
}

bool TTextSelector::GetLoopOptions() const {
  return ((text_selector_t*)(this->nativeObj))->loop_options;
}

TWidget TTimeClock::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TTimeClock((widget_t*)(time_clock_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TTimeClock::SetHour(int32_t hour) {
  return time_clock_set_hour(((widget_t*)(this->nativeObj)), hour);
}

ret_t TTimeClock::SetMinute(int32_t minute) {
  return time_clock_set_minute(((widget_t*)(this->nativeObj)), minute);
}

ret_t TTimeClock::SetSecond(int32_t second) {
  return time_clock_set_second(((widget_t*)(this->nativeObj)), second);
}

ret_t TTimeClock::SetHourImage(const char* hour) {
  return time_clock_set_hour_image(((widget_t*)(this->nativeObj)), hour);
}

ret_t TTimeClock::SetMinuteImage(const char* minute_image) {
  return time_clock_set_minute_image(((widget_t*)(this->nativeObj)), minute_image);
}

ret_t TTimeClock::SetSecondImage(const char* second_image) {
  return time_clock_set_second_image(((widget_t*)(this->nativeObj)), second_image);
}

ret_t TTimeClock::SetBgImage(const char* bg_image) {
  return time_clock_set_bg_image(((widget_t*)(this->nativeObj)), bg_image);
}

ret_t TTimeClock::SetImage(const char* image) {
  return time_clock_set_image(((widget_t*)(this->nativeObj)), image);
}

ret_t TTimeClock::SetHourAnchor(const char* anchor_x, const char* anchor_y) {
  return time_clock_set_hour_anchor(((widget_t*)(this->nativeObj)), anchor_x, anchor_y);
}

ret_t TTimeClock::SetMinuteAnchor(const char* anchor_x, const char* anchor_y) {
  return time_clock_set_minute_anchor(((widget_t*)(this->nativeObj)), anchor_x, anchor_y);
}

ret_t TTimeClock::SetSecondAnchor(const char* anchor_x, const char* anchor_y) {
  return time_clock_set_second_anchor(((widget_t*)(this->nativeObj)), anchor_x, anchor_y);
}

int32_t TTimeClock::GetHour() const {
  return ((time_clock_t*)(this->nativeObj))->hour;
}

int32_t TTimeClock::GetMinute() const {
  return ((time_clock_t*)(this->nativeObj))->minute;
}

int32_t TTimeClock::GetSecond() const {
  return ((time_clock_t*)(this->nativeObj))->second;
}

char* TTimeClock::GetImage() const {
  return ((time_clock_t*)(this->nativeObj))->image;
}

char* TTimeClock::GetBgImage() const {
  return ((time_clock_t*)(this->nativeObj))->bg_image;
}

char* TTimeClock::GetHourImage() const {
  return ((time_clock_t*)(this->nativeObj))->hour_image;
}

char* TTimeClock::GetMinuteImage() const {
  return ((time_clock_t*)(this->nativeObj))->minute_image;
}

char* TTimeClock::GetSecondImage() const {
  return ((time_clock_t*)(this->nativeObj))->second_image;
}

char* TTimeClock::GetHourAnchorX() const {
  return ((time_clock_t*)(this->nativeObj))->hour_anchor_x;
}

char* TTimeClock::GetHourAnchorY() const {
  return ((time_clock_t*)(this->nativeObj))->hour_anchor_y;
}

char* TTimeClock::GetMinuteAnchorX() const {
  return ((time_clock_t*)(this->nativeObj))->minute_anchor_x;
}

char* TTimeClock::GetMinuteAnchorY() const {
  return ((time_clock_t*)(this->nativeObj))->minute_anchor_y;
}

char* TTimeClock::GetSecondAnchorX() const {
  return ((time_clock_t*)(this->nativeObj))->second_anchor_x;
}

char* TTimeClock::GetSecondAnchorY() const {
  return ((time_clock_t*)(this->nativeObj))->second_anchor_y;
}

TWidget TVpage::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TVpage((widget_t*)(vpage_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TVpage::SetUiAsset(const char* ui_asset) {
  return vpage_set_ui_asset(((widget_t*)(this->nativeObj)), ui_asset);
}

ret_t TVpage::SetAnimHint(const char* anim_hint) {
  return vpage_set_anim_hint(((widget_t*)(this->nativeObj)), anim_hint);
}

char* TVpage::GetUiAsset() const {
  return ((vpage_t*)(this->nativeObj))->ui_asset;
}

char* TVpage::GetAnimHint() const {
  return ((vpage_t*)(this->nativeObj))->anim_hint;
}

const char* TPropChangeEvent::GetName() const {
  return ((prop_change_event_t*)(this->nativeObj))->name;
}

TValue TPropChangeEvent::GetValue() const {
  return TValue(((prop_change_event_t*)(this->nativeObj))->value);
}

uint32_t TProgressEvent::GetPercent() const {
  return ((progress_event_t*)(this->nativeObj))->percent;
}

ret_t TDoneEvent::GetResult() const {
  return ((done_event_t*)(this->nativeObj))->result;
}

int32_t TErrorEvent::GetCode() const {
  return ((error_event_t*)(this->nativeObj))->code;
}

const char* TErrorEvent::GetMessage() const {
  return ((error_event_t*)(this->nativeObj))->message;
}

const char* TCmdExecEvent::GetName() const {
  return ((cmd_exec_event_t*)(this->nativeObj))->name;
}

const char* TCmdExecEvent::GetArgs() const {
  return ((cmd_exec_event_t*)(this->nativeObj))->args;
}

ret_t TCmdExecEvent::GetResult() const {
  return ((cmd_exec_event_t*)(this->nativeObj))->result;
}

bool TCmdExecEvent::GetCanExec() const {
  return ((cmd_exec_event_t*)(this->nativeObj))->can_exec;
}

TWidget TAppBar::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TAppBar((widget_t*)(app_bar_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TButtonGroup::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TButtonGroup(
      (widget_t*)(button_group_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TButton::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TButton((widget_t*)(button_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TButton::SetRepeat(int32_t repeat) {
  return button_set_repeat(((widget_t*)(this->nativeObj)), repeat);
}

ret_t TButton::SetLongPressTime(uint32_t long_press_time) {
  return button_set_long_press_time(((widget_t*)(this->nativeObj)), long_press_time);
}

ret_t TButton::SetEnableLongPress(bool enable_long_press) {
  return button_set_enable_long_press(((widget_t*)(this->nativeObj)), enable_long_press);
}

int32_t TButton::GetRepeat() const {
  return ((button_t*)(this->nativeObj))->repeat;
}

bool TButton::GetEnableLongPress() const {
  return ((button_t*)(this->nativeObj))->enable_long_press;
}

uint32_t TButton::GetLongPressTime() const {
  return ((button_t*)(this->nativeObj))->long_press_time;
}

TWidget TCheckButton::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TCheckButton(
      (widget_t*)(check_button_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TCheckButton::CreateRadio(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TCheckButton(
      (widget_t*)(check_button_create_radio(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TCheckButton::SetValue(bool value) {
  return check_button_set_value(((widget_t*)(this->nativeObj)), value);
}

bool TCheckButton::GetValue() const {
  return ((check_button_t*)(this->nativeObj))->value;
}

TWidget TClipView::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TClipView((widget_t*)(clip_view_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TColorTile::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TColorTile((widget_t*)(color_tile_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TColorTile::SetBgColor(const char* color) {
  return color_tile_set_bg_color(((widget_t*)(this->nativeObj)), color);
}

const char* TColorTile::GetBgColor() {
  return color_tile_get_bg_color(((widget_t*)(this->nativeObj)));
}

const char* TColorTile::GetBorderColor() {
  return color_tile_get_border_color(((widget_t*)(this->nativeObj)));
}

const char* TColorTile::GetBgColor() const {
  return ((color_tile_t*)(this->nativeObj))->bg_color;
}

const char* TColorTile::GetBorderColor() const {
  return ((color_tile_t*)(this->nativeObj))->border_color;
}

TWidget TColumn::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TColumn((widget_t*)(column_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TComboBoxItem::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TComboBoxItem(
      (widget_t*)(combo_box_item_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TComboBoxItem::SetChecked(bool checked) {
  return combo_box_item_set_checked(((widget_t*)(this->nativeObj)), checked);
}

ret_t TComboBoxItem::SetValue(int32_t value) {
  return combo_box_item_set_value(((widget_t*)(this->nativeObj)), value);
}

int32_t TComboBoxItem::GetValue() const {
  return ((combo_box_item_t*)(this->nativeObj))->value;
}

bool TComboBoxItem::GetChecked() const {
  return ((combo_box_item_t*)(this->nativeObj))->checked;
}

TWidget TDialogClient::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TDialogClient(
      (widget_t*)(dialog_client_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TDialogTitle::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TDialogTitle(
      (widget_t*)(dialog_title_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TDigitClock::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TDigitClock((widget_t*)(digit_clock_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TDigitClock::SetFormat(const char* format) {
  return digit_clock_set_format(((widget_t*)(this->nativeObj)), format);
}

char* TDigitClock::GetFormat() const {
  return ((digit_clock_t*)(this->nativeObj))->format;
}

TWidget TDragger::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TDragger((widget_t*)(dragger_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TDragger::SetRange(xy_t x_min, xy_t y_min, xy_t x_max, xy_t y_max) {
  return dragger_set_range(((widget_t*)(this->nativeObj)), x_min, y_min, x_max, y_max);
}

xy_t TDragger::GetXMin() const {
  return ((dragger_t*)(this->nativeObj))->x_min;
}

xy_t TDragger::GetYMin() const {
  return ((dragger_t*)(this->nativeObj))->y_min;
}

xy_t TDragger::GetXMax() const {
  return ((dragger_t*)(this->nativeObj))->x_max;
}

xy_t TDragger::GetYMax() const {
  return ((dragger_t*)(this->nativeObj))->y_max;
}

TWidget TEdit::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TEdit((widget_t*)(edit_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

int32_t TEdit::GetInt() {
  return edit_get_int(((widget_t*)(this->nativeObj)));
}

double TEdit::GetDouble() {
  return edit_get_double(((widget_t*)(this->nativeObj)));
}

ret_t TEdit::SetInt(int32_t value) {
  return edit_set_int(((widget_t*)(this->nativeObj)), value);
}

ret_t TEdit::SetDouble(double value) {
  return edit_set_double(((widget_t*)(this->nativeObj)), value);
}

ret_t TEdit::SetTextLimit(uint32_t min, uint32_t max) {
  return edit_set_text_limit(((widget_t*)(this->nativeObj)), min, max);
}

ret_t TEdit::SetIntLimit(int32_t min, int32_t max, uint32_t step) {
  return edit_set_int_limit(((widget_t*)(this->nativeObj)), min, max, step);
}

ret_t TEdit::SetFloatLimit(double min, double max, double step) {
  return edit_set_float_limit(((widget_t*)(this->nativeObj)), min, max, step);
}

ret_t TEdit::SetReadonly(bool readonly) {
  return edit_set_readonly(((widget_t*)(this->nativeObj)), readonly);
}

ret_t TEdit::SetCancelable(bool cancelable) {
  return edit_set_cancelable(((widget_t*)(this->nativeObj)), cancelable);
}

ret_t TEdit::SetAutoFix(bool auto_fix) {
  return edit_set_auto_fix(((widget_t*)(this->nativeObj)), auto_fix);
}

ret_t TEdit::SetSelectNoneWhenFocused(bool select_none_when_focused) {
  return edit_set_select_none_when_focused(((widget_t*)(this->nativeObj)),
                                           select_none_when_focused);
}

ret_t TEdit::SetOpenImWhenFocused(bool open_im_when_focused) {
  return edit_set_open_im_when_focused(((widget_t*)(this->nativeObj)), open_im_when_focused);
}

ret_t TEdit::SetCloseImWhenBlured(bool close_im_when_blured) {
  return edit_set_close_im_when_blured(((widget_t*)(this->nativeObj)), close_im_when_blured);
}

ret_t TEdit::SetInputType(input_type_t type) {
  return edit_set_input_type(((widget_t*)(this->nativeObj)), type);
}

ret_t TEdit::SetActionText(char* action_text) {
  return edit_set_action_text(((widget_t*)(this->nativeObj)), action_text);
}

ret_t TEdit::SetTips(char* tips) {
  return edit_set_tips(((widget_t*)(this->nativeObj)), tips);
}

ret_t TEdit::SetTrTips(const char* tr_tips) {
  return edit_set_tr_tips(((widget_t*)(this->nativeObj)), tr_tips);
}

ret_t TEdit::SetKeyboard(char* keyboard) {
  return edit_set_keyboard(((widget_t*)(this->nativeObj)), keyboard);
}

ret_t TEdit::SetPasswordVisible(bool password_visible) {
  return edit_set_password_visible(((widget_t*)(this->nativeObj)), password_visible);
}

ret_t TEdit::SetFocus(bool focus) {
  return edit_set_focus(((widget_t*)(this->nativeObj)), focus);
}

ret_t TEdit::SetCursor(uint32_t cursor) {
  return edit_set_cursor(((widget_t*)(this->nativeObj)), cursor);
}

uint32_t TEdit::GetCursor() {
  return edit_get_cursor(((widget_t*)(this->nativeObj)));
}

ret_t TEdit::SetSelect(uint32_t start, uint32_t end) {
  return edit_set_select(((widget_t*)(this->nativeObj)), start, end);
}

char* TEdit::GetSelectedText() {
  return edit_get_selected_text(((widget_t*)(this->nativeObj)));
}

char* TEdit::GetTips() const {
  return ((edit_t*)(this->nativeObj))->tips;
}

char* TEdit::GetTrTips() const {
  return ((edit_t*)(this->nativeObj))->tr_tips;
}

char* TEdit::GetActionText() const {
  return ((edit_t*)(this->nativeObj))->action_text;
}

char* TEdit::GetKeyboard() const {
  return ((edit_t*)(this->nativeObj))->keyboard;
}

double TEdit::GetMin() const {
  return ((edit_t*)(this->nativeObj))->min;
}

double TEdit::GetMax() const {
  return ((edit_t*)(this->nativeObj))->max;
}

double TEdit::GetStep() const {
  return ((edit_t*)(this->nativeObj))->step;
}

input_type_t TEdit::GetInputType() const {
  return ((edit_t*)(this->nativeObj))->input_type;
}

bool TEdit::GetReadonly() const {
  return ((edit_t*)(this->nativeObj))->readonly;
}

bool TEdit::GetPasswordVisible() const {
  return ((edit_t*)(this->nativeObj))->password_visible;
}

bool TEdit::GetAutoFix() const {
  return ((edit_t*)(this->nativeObj))->auto_fix;
}

bool TEdit::GetSelectNoneWhenFocused() const {
  return ((edit_t*)(this->nativeObj))->select_none_when_focused;
}

bool TEdit::GetOpenImWhenFocused() const {
  return ((edit_t*)(this->nativeObj))->open_im_when_focused;
}

bool TEdit::GetCloseImWhenBlured() const {
  return ((edit_t*)(this->nativeObj))->close_im_when_blured;
}

bool TEdit::GetCancelable() const {
  return ((edit_t*)(this->nativeObj))->cancelable;
}

TWidget TGridItem::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TGridItem((widget_t*)(grid_item_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TGrid::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TGrid((widget_t*)(grid_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TGroupBox::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TGroupBox((widget_t*)(group_box_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TLabel::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TLabel((widget_t*)(label_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TLabel::SetLength(int32_t length) {
  return label_set_length(((widget_t*)(this->nativeObj)), length);
}

ret_t TLabel::SetMaxW(int32_t max_w) {
  return label_set_max_w(((widget_t*)(this->nativeObj)), max_w);
}

ret_t TLabel::SetLineWrap(bool line_wrap) {
  return label_set_line_wrap(((widget_t*)(this->nativeObj)), line_wrap);
}

ret_t TLabel::SetWordWrap(bool word_wrap) {
  return label_set_word_wrap(((widget_t*)(this->nativeObj)), word_wrap);
}

ret_t TLabel::ResizeToContent(uint32_t min_w, uint32_t max_w, uint32_t min_h, uint32_t max_h) {
  return label_resize_to_content(((widget_t*)(this->nativeObj)), min_w, max_w, min_h, max_h);
}

int32_t TLabel::GetLength() const {
  return ((label_t*)(this->nativeObj))->length;
}

bool TLabel::GetLineWrap() const {
  return ((label_t*)(this->nativeObj))->line_wrap;
}

bool TLabel::GetWordWrap() const {
  return ((label_t*)(this->nativeObj))->word_wrap;
}

int32_t TLabel::GetMaxW() const {
  return ((label_t*)(this->nativeObj))->max_w;
}

TWidget TPages::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TPages((widget_t*)(pages_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TPages::SetActive(uint32_t index) {
  return pages_set_active(((widget_t*)(this->nativeObj)), index);
}

ret_t TPages::SetActiveByName(char* name) {
  return pages_set_active_by_name(((widget_t*)(this->nativeObj)), name);
}

uint32_t TPages::GetActive() const {
  return ((pages_t*)(this->nativeObj))->active;
}

TWidget TProgressBar::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TProgressBar(
      (widget_t*)(progress_bar_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TProgressBar::SetValue(double value) {
  return progress_bar_set_value(((widget_t*)(this->nativeObj)), value);
}

ret_t TProgressBar::SetMax(double max) {
  return progress_bar_set_max(((widget_t*)(this->nativeObj)), max);
}

ret_t TProgressBar::SetFormat(const char* format) {
  return progress_bar_set_format(((widget_t*)(this->nativeObj)), format);
}

ret_t TProgressBar::SetVertical(bool vertical) {
  return progress_bar_set_vertical(((widget_t*)(this->nativeObj)), vertical);
}

ret_t TProgressBar::SetShowText(bool show_text) {
  return progress_bar_set_show_text(((widget_t*)(this->nativeObj)), show_text);
}

ret_t TProgressBar::SetReverse(bool reverse) {
  return progress_bar_set_reverse(((widget_t*)(this->nativeObj)), reverse);
}

uint32_t TProgressBar::GetPercent() {
  return progress_bar_get_percent(((widget_t*)(this->nativeObj)));
}

double TProgressBar::GetValue() const {
  return ((progress_bar_t*)(this->nativeObj))->value;
}

double TProgressBar::GetMax() const {
  return ((progress_bar_t*)(this->nativeObj))->max;
}

char* TProgressBar::GetFormat() const {
  return ((progress_bar_t*)(this->nativeObj))->format;
}

bool TProgressBar::GetVertical() const {
  return ((progress_bar_t*)(this->nativeObj))->vertical;
}

bool TProgressBar::GetShowText() const {
  return ((progress_bar_t*)(this->nativeObj))->show_text;
}

bool TProgressBar::GetReverse() const {
  return ((progress_bar_t*)(this->nativeObj))->reverse;
}

TWidget TRow::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TRow((widget_t*)(row_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TSlider::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TSlider((widget_t*)(slider_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TSlider::SetValue(double value) {
  return slider_set_value(((widget_t*)(this->nativeObj)), value);
}

ret_t TSlider::SetMin(double min) {
  return slider_set_min(((widget_t*)(this->nativeObj)), min);
}

ret_t TSlider::SetMax(double max) {
  return slider_set_max(((widget_t*)(this->nativeObj)), max);
}

ret_t TSlider::SetStep(double step) {
  return slider_set_step(((widget_t*)(this->nativeObj)), step);
}

ret_t TSlider::SetBarSize(uint32_t bar_size) {
  return slider_set_bar_size(((widget_t*)(this->nativeObj)), bar_size);
}

ret_t TSlider::SetVertical(bool vertical) {
  return slider_set_vertical(((widget_t*)(this->nativeObj)), vertical);
}

double TSlider::GetValue() const {
  return ((slider_t*)(this->nativeObj))->value;
}

double TSlider::GetMin() const {
  return ((slider_t*)(this->nativeObj))->min;
}

double TSlider::GetMax() const {
  return ((slider_t*)(this->nativeObj))->max;
}

double TSlider::GetStep() const {
  return ((slider_t*)(this->nativeObj))->step;
}

bool TSlider::GetVertical() const {
  return ((slider_t*)(this->nativeObj))->vertical;
}

uint32_t TSlider::GetBarSize() const {
  return ((slider_t*)(this->nativeObj))->bar_size;
}

uint32_t TSlider::GetDraggerSize() const {
  return ((slider_t*)(this->nativeObj))->dragger_size;
}

bool TSlider::GetDraggerAdaptToIcon() const {
  return ((slider_t*)(this->nativeObj))->dragger_adapt_to_icon;
}

bool TSlider::GetSlideWithBar() const {
  return ((slider_t*)(this->nativeObj))->slide_with_bar;
}

TWidget TTabButtonGroup::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TTabButtonGroup(
      (widget_t*)(tab_button_group_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TTabButtonGroup::SetCompact(bool compact) {
  return tab_button_group_set_compact(((widget_t*)(this->nativeObj)), compact);
}

ret_t TTabButtonGroup::SetScrollable(bool scrollable) {
  return tab_button_group_set_scrollable(((widget_t*)(this->nativeObj)), scrollable);
}

bool TTabButtonGroup::GetCompact() const {
  return ((tab_button_group_t*)(this->nativeObj))->compact;
}

bool TTabButtonGroup::GetScrollable() const {
  return ((tab_button_group_t*)(this->nativeObj))->scrollable;
}

TWidget TTabButton::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TTabButton((widget_t*)(tab_button_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TTabButton::SetValue(bool value) {
  return tab_button_set_value(((widget_t*)(this->nativeObj)), value);
}

ret_t TTabButton::SetIcon(char* name) {
  return tab_button_set_icon(((widget_t*)(this->nativeObj)), name);
}

ret_t TTabButton::SetActiveIcon(char* name) {
  return tab_button_set_active_icon(((widget_t*)(this->nativeObj)), name);
}

ret_t TTabButton::SetLoadUi(char* name) {
  return tab_button_set_load_ui(((widget_t*)(this->nativeObj)), name);
}

bool TTabButton::GetValue() const {
  return ((tab_button_t*)(this->nativeObj))->value;
}

char* TTabButton::GetLoadUi() const {
  return ((tab_button_t*)(this->nativeObj))->load_ui;
}

char* TTabButton::GetActiveIcon() const {
  return ((tab_button_t*)(this->nativeObj))->active_icon;
}

char* TTabButton::GetIcon() const {
  return ((tab_button_t*)(this->nativeObj))->icon;
}

TWidget TTabControl::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TTabControl((widget_t*)(tab_control_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TView::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TView((widget_t*)(view_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TView::SetDefaultFocusedChild(const char* default_focused_child) {
  return view_set_default_focused_child(((widget_t*)(this->nativeObj)), default_focused_child);
}

char* TView::GetDefaultFocusedChild() const {
  return ((view_t*)(this->nativeObj))->default_focused_child;
}

TWidget TDialog::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TDialog((widget_t*)(dialog_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TDialog::CreateSimple(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TDialog((widget_t*)(dialog_create_simple(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TDialog::GetTitle() {
  return TWidget((widget_t*)(dialog_get_title(((widget_t*)(this->nativeObj)))));
}

TWidget TDialog::GetClient() {
  return TWidget((widget_t*)(dialog_get_client(((widget_t*)(this->nativeObj)))));
}

TWidget TDialog::Open(const char* name) {
  return TDialog((widget_t*)(dialog_open(name)));
}

ret_t TDialog::SetTitle(char* title) {
  return dialog_set_title(((widget_t*)(this->nativeObj)), title);
}

dialog_quit_code_t TDialog::Modal() {
  return dialog_modal(((widget_t*)(this->nativeObj)));
}

ret_t TDialog::Quit(uint32_t code) {
  return dialog_quit(((widget_t*)(this->nativeObj)), code);
}

bool TDialog::IsQuited() {
  return dialog_is_quited(((widget_t*)(this->nativeObj)));
}

bool TDialog::IsModal() {
  return dialog_is_modal(((widget_t*)(this->nativeObj)));
}

ret_t TDialog::Toast(const char* text, uint32_t duration) {
  return dialog_toast(text, duration);
}

ret_t TDialog::Info(const char* title, const char* text) {
  return dialog_info(title, text);
}

ret_t TDialog::Warn(const char* title, const char* text) {
  return dialog_warn(title, text);
}

ret_t TDialog::Confirm(const char* title, const char* text) {
  return dialog_confirm(title, text);
}

const char* TDialog::GetHighlight() const {
  return ((dialog_t*)(this->nativeObj))->highlight;
}

ret_t TNativeWindow::Move(xy_t x, xy_t y, bool force) {
  return native_window_move(((native_window_t*)(this->nativeObj)), x, y, force);
}

ret_t TNativeWindow::Resize(wh_t w, wh_t h, bool force) {
  return native_window_resize(((native_window_t*)(this->nativeObj)), w, h, force);
}

ret_t TNativeWindow::Minimize() {
  return native_window_minimize(((native_window_t*)(this->nativeObj)));
}

ret_t TNativeWindow::Maximize() {
  return native_window_maximize(((native_window_t*)(this->nativeObj)));
}

ret_t TNativeWindow::Restore() {
  return native_window_restore(((native_window_t*)(this->nativeObj)));
}

ret_t TNativeWindow::Center() {
  return native_window_center(((native_window_t*)(this->nativeObj)));
}

ret_t TNativeWindow::ShowBorder(bool show) {
  return native_window_show_border(((native_window_t*)(this->nativeObj)), show);
}

ret_t TNativeWindow::SetFullscreen(bool fullscreen) {
  return native_window_set_fullscreen(((native_window_t*)(this->nativeObj)), fullscreen);
}

ret_t TNativeWindow::SetCursor(const char* name, TBitmap& img) {
  return native_window_set_cursor(((native_window_t*)(this->nativeObj)), name,
                                  ((bitmap_t*)(img.nativeObj)));
}

TWidget TWindow::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TWindow((widget_t*)(window_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TWindow::CreateDefault() {
  return TWindow((widget_t*)(window_create_default()));
}

ret_t TWindow::SetFullscreen(bool fullscreen) {
  return window_set_fullscreen(((widget_t*)(this->nativeObj)), fullscreen);
}

ret_t TWindow::SetAutoScaleChildren(uint32_t design_w, uint32_t design_h) {
  return window_set_auto_scale_children(((widget_t*)(this->nativeObj)), design_w, design_h);
}

TWidget TWindow::Open(const char* name) {
  return TWindow((widget_t*)(window_open(name)));
}

TWidget TWindow::OpenAndClose(const char* name, TWidget& to_close) {
  return TWindow((widget_t*)(window_open_and_close(name, ((widget_t*)(to_close.nativeObj)))));
}

ret_t TWindow::Close() {
  return window_close(((widget_t*)(this->nativeObj)));
}

ret_t TWindow::CloseForce() {
  return window_close_force(((widget_t*)(this->nativeObj)));
}

bool TWindow::GetFullscreen() const {
  return ((window_t*)(this->nativeObj))->fullscreen;
}

TWidget TGifImage::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TGifImage((widget_t*)(gif_image_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TGifImage::Play() {
  return gif_image_play(((widget_t*)(this->nativeObj)));
}

ret_t TGifImage::Stop() {
  return gif_image_stop(((widget_t*)(this->nativeObj)));
}

ret_t TGifImage::Pause() {
  return gif_image_pause(((widget_t*)(this->nativeObj)));
}

TWidget TKeyboard::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TKeyboard((widget_t*)(keyboard_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TSvgImage::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TSvgImage((widget_t*)(svg_image_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TSvgImage::SetImage(char* name) {
  return svg_image_set_image(((widget_t*)(this->nativeObj)), name);
}

void* TIdleInfo::GetCtx() const {
  return ((idle_info_t*)(this->nativeObj))->ctx;
}

void* TIdleInfo::GetExtraCtx() const {
  return ((idle_info_t*)(this->nativeObj))->extra_ctx;
}

uint32_t TIdleInfo::GetId() const {
  return ((idle_info_t*)(this->nativeObj))->id;
}

TObject TObjectArray::Create() {
  return TObjectArray((emitter_t*)(object_array_create()));
}

ret_t TObjectArray::Unref() {
  return object_array_unref(((object_t*)(this->nativeObj)));
}

ret_t TObjectArray::ClearProps() {
  return object_array_clear_props(((object_t*)(this->nativeObj)));
}

ret_t TObjectArray::Insert(uint32_t index, TValue& v) {
  return object_array_insert(((object_t*)(this->nativeObj)), index,
                             ((const value_t*)(v.nativeObj)));
}

ret_t TObjectArray::Push(TValue& v) {
  return object_array_push(((object_t*)(this->nativeObj)), ((const value_t*)(v.nativeObj)));
}

int32_t TObjectArray::IndexOf(TValue& v) {
  return object_array_index_of(((object_t*)(this->nativeObj)), ((const value_t*)(v.nativeObj)));
}

int32_t TObjectArray::LastIndexOf(TValue& v) {
  return object_array_last_index_of(((object_t*)(this->nativeObj)),
                                    ((const value_t*)(v.nativeObj)));
}

ret_t TObjectArray::Remove(uint32_t index) {
  return object_array_remove(((object_t*)(this->nativeObj)), index);
}

ret_t TObjectArray::GetAndRemove(uint32_t index, TValue& v) {
  return object_array_get_and_remove(((object_t*)(this->nativeObj)), index,
                                     ((value_t*)(v.nativeObj)));
}

uint32_t TObjectArray::GetSize() const {
  return ((object_array_t*)(this->nativeObj))->size;
}

TObject TObjectDefault::Create() {
  return TObjectDefault((emitter_t*)(object_default_create()));
}

ret_t TObjectDefault::Unref() {
  return object_default_unref(((object_t*)(this->nativeObj)));
}

ret_t TObjectDefault::ClearProps() {
  return object_default_clear_props(((object_t*)(this->nativeObj)));
}

uint32_t TObjectDefault::GetPropsSize() const {
  return ((object_default_t*)(this->nativeObj))->props_size;
}

void* TTimerInfo::GetCtx() const {
  return ((timer_info_t*)(this->nativeObj))->ctx;
}

void* TTimerInfo::GetExtraCtx() const {
  return ((timer_info_t*)(this->nativeObj))->extra_ctx;
}

uint32_t TTimerInfo::GetId() const {
  return ((timer_info_t*)(this->nativeObj))->id;
}

uint64_t TTimerInfo::GetNow() const {
  return ((timer_info_t*)(this->nativeObj))->now;
}

TWidget TComboBox::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TComboBox((widget_t*)(combo_box_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TComboBox::SetOpenWindow(const char* open_window) {
  return combo_box_set_open_window(((widget_t*)(this->nativeObj)), open_window);
}

ret_t TComboBox::ResetOptions() {
  return combo_box_reset_options(((widget_t*)(this->nativeObj)));
}

int32_t TComboBox::CountOptions() {
  return combo_box_count_options(((widget_t*)(this->nativeObj)));
}

ret_t TComboBox::SetSelectedIndex(uint32_t index) {
  return combo_box_set_selected_index(((widget_t*)(this->nativeObj)), index);
}

ret_t TComboBox::SetLocalizeOptions(bool localize_options) {
  return combo_box_set_localize_options(((widget_t*)(this->nativeObj)), localize_options);
}

ret_t TComboBox::SetValue(int32_t value) {
  return combo_box_set_value(((widget_t*)(this->nativeObj)), value);
}

ret_t TComboBox::SetItemHeight(uint32_t item_height) {
  return combo_box_set_item_height(((widget_t*)(this->nativeObj)), item_height);
}

ret_t TComboBox::AppendOption(int32_t value, const char* text) {
  return combo_box_append_option(((widget_t*)(this->nativeObj)), value, text);
}

ret_t TComboBox::SetOptions(const char* options) {
  return combo_box_set_options(((widget_t*)(this->nativeObj)), options);
}

int32_t TComboBox::GetValue() {
  return combo_box_get_value(((widget_t*)(this->nativeObj)));
}

const char* TComboBox::GetTextValue() {
  return combo_box_get_text(((widget_t*)(this->nativeObj)));
}

char* TComboBox::GetOpenWindow() const {
  return ((combo_box_t*)(this->nativeObj))->open_window;
}

int32_t TComboBox::GetSelectedIndex() const {
  return ((combo_box_t*)(this->nativeObj))->selected_index;
}

int32_t TComboBox::GetValue() const {
  return ((combo_box_t*)(this->nativeObj))->value;
}

bool TComboBox::GetLocalizeOptions() const {
  return ((combo_box_t*)(this->nativeObj))->localize_options;
}

char* TComboBox::GetOptions() const {
  return ((combo_box_t*)(this->nativeObj))->options;
}

int32_t TComboBox::GetItemHeight() const {
  return ((combo_box_t*)(this->nativeObj))->item_height;
}

TWidget TImage::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TImage((widget_t*)(image_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TImage::SetDrawType(image_draw_type_t draw_type) {
  return image_set_draw_type(((widget_t*)(this->nativeObj)), draw_type);
}

image_draw_type_t TImage::GetDrawType() const {
  return ((image_t*)(this->nativeObj))->draw_type;
}

TWidget TOverlay::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TOverlay((widget_t*)(overlay_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TOverlay::SetClickThrough(bool click_through) {
  return overlay_set_click_through(((widget_t*)(this->nativeObj)), click_through);
}

ret_t TOverlay::SetAlwaysOnTop(bool always_on_top) {
  return overlay_set_always_on_top(((widget_t*)(this->nativeObj)), always_on_top);
}

bool TOverlay::GetClickThrough() const {
  return ((overlay_t*)(this->nativeObj))->click_through;
}

bool TOverlay::GetAlwaysOnTop() const {
  return ((overlay_t*)(this->nativeObj))->always_on_top;
}

TWidget TPopup::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TPopup((widget_t*)(popup_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

ret_t TPopup::SetCloseWhenClick(bool close_when_click) {
  return popup_set_close_when_click(((widget_t*)(this->nativeObj)), close_when_click);
}

ret_t TPopup::SetCloseWhenClickOutside(bool close_when_click_outside) {
  return popup_set_close_when_click_outside(((widget_t*)(this->nativeObj)),
                                            close_when_click_outside);
}

ret_t TPopup::SetCloseWhenTimeout(uint32_t close_when_timeout) {
  return popup_set_close_when_timeout(((widget_t*)(this->nativeObj)), close_when_timeout);
}

bool TPopup::GetCloseWhenClick() const {
  return ((popup_t*)(this->nativeObj))->close_when_click;
}

bool TPopup::GetCloseWhenClickOutside() const {
  return ((popup_t*)(this->nativeObj))->close_when_click_outside;
}

uint32_t TPopup::GetCloseWhenTimeout() const {
  return ((popup_t*)(this->nativeObj))->close_when_timeout;
}

TWidget TSpinBox::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TSpinBox((widget_t*)(spin_box_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TSystemBar::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TSystemBar((widget_t*)(system_bar_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}

TWidget TComboBoxEx::Create(TWidget& parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  return TComboBoxEx((widget_t*)(combo_box_ex_create(((widget_t*)(parent.nativeObj)), x, y, w, h)));
}
