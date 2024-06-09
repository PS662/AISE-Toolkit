from msrest.authentication import CognitiveServicesCredentials
from azure.cognitiveservices.vision.face import FaceClient

import cv2
from IPython.display import Image
from matplotlib import pyplot as plt
from regex import W
from time import time

attributes_list = ['age', 'emotion', 'gender', 'accessories']
fps = 1
fps = fps * 1000

subscription_key = "<your_key_here>"
endpoint = "https://visionfaceprateek.cognitiveservices.azure.com/"
cv_face_client = FaceClient(
    endpoint, CognitiveServicesCredentials(subscription_key))
print("Connected to resource", cv_face_client)

def process_frame(frame2api):
    cv2.imwrite('tmp_image.jpg', frame2api)
    tmp_img = open("tmp_image.jpg", 'rb')
    detected_faces = cv_face_client.face.detect_with_stream(
        tmp_img, return_face_attributes=attributes_list)
    tmp_img.close()
    return detected_faces

font = cv2.FONT_HERSHEY_SIMPLEX
fontScale = 1
color = (0, 0, 255)
thickness = 2


def process_result(frame2api, detected_faces):
    if len(detected_faces) > 0:
        print("Number of faces detected:", len(detected_faces))
        for faces_itr in range(len(detected_faces)):
            org = (detected_faces[faces_itr].face_rectangle.left,
                   detected_faces[faces_itr].face_rectangle.top)
            gender = detected_faces[faces_itr].face_attributes.gender.value
            age = detected_faces[faces_itr].face_attributes.age
            emotions_dict = detected_faces[faces_itr].face_attributes.emotion.as_dict(
            )
            emotion_name = max(
                zip(emotions_dict.values(), emotions_dict.keys()))[1]

            face_rect = [detected_faces[faces_itr].face_rectangle.left,
                         detected_faces[faces_itr].face_rectangle.top,
                         detected_faces[faces_itr].face_rectangle.width,
                         detected_faces[faces_itr].face_rectangle.height]

            frame2api = cv2.rectangle(frame2api, face_rect, (0, 0, 255), 5)
            frame2api = cv2.putText(frame2api, str(
                gender), org, font, fontScale, color, thickness, cv2.LINE_AA)
            frame2api = cv2.putText(frame2api, str(
                age), (org[0]+100, org[1]), font, fontScale, color, thickness, cv2.LINE_AA)
            frame2api = cv2.putText(frame2api, str(
                emotion_name), (org[0] + 200, org[1]), font, fontScale, color, thickness, cv2.LINE_AA)
    else:
        print("No Face Detected")
    return len(detected_faces)



vid = cv2.VideoCapture(0, cv2.CAP_DSHOW)
#vid = cv2.VideoCapture(0)
start_time = time() * 1000
init_frame = True

while (True):
    _, frame = vid.read()
    if init_frame:
        frame2api = frame.copy()
        detected_faces = process_frame(frame2api)
        process_result(frame2api, detected_faces)
        init_frame = False

    end_time = time() * 1000
    time_diff = end_time - start_time
    if (int(time_diff) >= fps):
        print("Send this frame", time(), time_diff)
        frame2api = frame.copy()
        detected_faces = process_frame(frame2api)
        process_result(frame2api, detected_faces)
        start_time = time() * 1000
    else:
        print("Skip this frame", time(), time_diff)

    frame = cv2.putText(frame, "Real Time", (10,10), font,
                        fontScale, color, thickness, cv2.LINE_AA)
    frame2api = cv2.putText(frame2api, "Processed", (50,50),
                            font, fontScale, color, thickness, cv2.LINE_AA)
    frame_merged = cv2.hconcat([frame, frame2api])
    cv2.imshow("Display", frame_merged)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
vid.release()
cv2.destroyAllWindows()
